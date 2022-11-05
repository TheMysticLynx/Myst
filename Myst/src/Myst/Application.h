//
// Created by Kaiden Howard on 10/28/22.
//

#ifndef MYST_APPLICATION_H
#define MYST_APPLICATION_H
#include "pch.h"
#include "Core.h"
#include "Window.h"

namespace Myst {

    MYST_API class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& event);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        bool OnWindowClose(const Event &event);
    };

    // To be defined in client
    Application* CreateApplication();
} // Myst

#endif //MYST_APPLICATION_H
