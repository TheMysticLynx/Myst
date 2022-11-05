//
// Created by Kaiden Howard on 11/3/22.
//

#include "GlfwWindow.h"
#include "Myst/pch.h"
#include "Myst/Events/ApplicationEvent.h"
#include "Myst/Events/KeyEvent.h"
#include "Myst/Events/MouseEvent.h"
#include <GLFW/glfw3.h>

namespace Myst {

    bool GlfwWindow::s_GLFWInitialized = false;

    GlfwWindow::GlfwWindow(const Myst::WindowProps &windowProps) : Window(windowProps) { // NOLINT(cppcoreguidelines-pro-type-member-init)
        Init(windowProps);
    }

    GlfwWindow::~GlfwWindow() {
        Shutdown();
    }

    void GlfwWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);

        if(glfwWindowShouldClose(m_Window)) {
            Shutdown();
        }
    }

    void GlfwWindow::SetEventCallback(const Myst::Window::EventCallbackFn &callback) {
        m_Data.eventCallback = callback;
    }

    void GlfwWindow::SetVSync(bool enabled) {
        if(enabled) {
            glfwSwapInterval(1);
            vsync = true;
        } else {
            glfwSwapInterval(0);
            vsync = false;
        }
    }

    bool GlfwWindow::IsVSync() {
        return this->vsync;
    }

    void GlfwWindow::Init(const WindowProps& props) {
        m_Data.Title = props.Name;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if(!s_GLFWInitialized) {
            int success = glfwInit();

            ASSERT(if(!success) {
                MYST_CORE_ERROR("Couldn't initiate GLFW");
            })

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Name.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
            auto* data = (WindowData*)glfwGetWindowUserPointer(window);
            data->Width = width;
            data->Height = height;

            WindowResizeEvent event(width, height);
            data->eventCallback(event);

        });
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            auto *data = (WindowData*)glfwGetWindowUserPointer(window);

            Event* event;

            switch (action) {
                case GLFW_PRESS:
                    event = new KeyPressedEvent(key, false);
                    break;
                case GLFW_REPEAT:
                    event = new KeyPressedEvent(key, true);
                    break;
                case GLFW_RELEASE:
                    event = new KeyReleasedEvent(key);
                    break;
                default:
                    event = nullptr;
                    break;
            }

            if(event != nullptr)
                data->eventCallback(*event);
            delete event;
        });
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
           WindowCloseEvent event;
           auto* data = (WindowData*)glfwGetWindowUserPointer(window);

           data->eventCallback(event);
        });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){
            auto *data = (WindowData*)glfwGetWindowUserPointer(window);

            Event* event;

            switch (action) {
                case GLFW_PRESS:
                    event = new MouseButtonDown(button, false);
                    break;
                case GLFW_REPEAT:
                    event = new MouseButtonDown(button, true);
                    break;
                case GLFW_RELEASE:
                    event = new MouseButtonUp(button);
                    break;
                default:
                    event = nullptr;
                    break;
            }

            if(event != nullptr)
                data->eventCallback(*event);
            delete event;
        });
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y){
            auto* data = (WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)x, (float)y);

            data->eventCallback(event);
        });
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double x, double y) {
            auto* data = (WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)x, (float)y);

            data->eventCallback(event);
        });
        MYST_CORE_INFO("Created window {0}px by {1}px called {2}", props.Width, props.Height, props.Name);
    }

    void GlfwWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

    Window *Window::Create(const Myst::WindowProps &props) {
        return new GlfwWindow(props);
    }
}