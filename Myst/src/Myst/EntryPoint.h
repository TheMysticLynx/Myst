//
// Created by Kaiden Howard on 10/28/22.
//

#include "Core.h"
#include "Application.h"

#ifndef MYST_ENTRYPOINT_H
#define MYST_ENTRYPOINT_H

#ifdef MYST_PLATFORM_MAC

int main() {
    auto app = Myst::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif

#endif //MYST_ENTRYPOINT_H