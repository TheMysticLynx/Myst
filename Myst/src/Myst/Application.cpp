//
// Created by Kaiden Howard on 10/28/22.
//
#include "pch.h"
#include "Application.h"
#include "Myst/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>


namespace Myst {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application() {
        MYST_CORE_INFO("Client started");
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        MYST_CORE_INFO("{0}", event.ToString());
    }

    bool Application::OnWindowClose(const Event& event) {
        m_Running = false;
        return true;
    }
} // Myst