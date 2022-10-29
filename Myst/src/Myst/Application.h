//
// Created by Kaiden Howard on 10/28/22.
//

#ifndef MYST_APPLICATION_H
#define MYST_APPLICATION_H

#include "Core.h"

namespace Myst {

    MYST_API class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in client
    Application* CreateApplication();
} // Myst

#endif //MYST_APPLICATION_H
