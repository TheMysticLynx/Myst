//
// Created by Kaiden Howard on 11/3/22.
//

#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

namespace Myst {
    class GlfwWindow : public Window{
    public:
        explicit GlfwWindow(const WindowProps &windowProps);
        ~GlfwWindow() override;
        void OnUpdate() override;
        [[nodiscard]] inline unsigned int GetWidth() const override { return m_Width; };
        [[nodiscard]] inline unsigned int GetHeight() const override{ return m_Height; };
        void SetEventCallback(const EventCallbackFn &callback) override;
        void SetVSync(bool enabled) override;
        [[nodiscard]]bool IsVSync() override;
    private:
        void Init(const WindowProps& props);
        void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn eventCallback;
        };

        WindowData m_Data;

        unsigned int m_Width, m_Height;
        static bool s_GLFWInitialized;
        bool vsync = false;
    };
}

