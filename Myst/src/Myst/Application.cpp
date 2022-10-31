//
// Created by Kaiden Howard on 10/28/22.
//

#include "Application.h"
#include <iostream>
#include <spdlog/spdlog.h>
#include "Log.h"


namespace Myst {
    Application::Application() {
        MYST_CORE_INFO("Client started");
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (true) {

        }
    }


} // Myst