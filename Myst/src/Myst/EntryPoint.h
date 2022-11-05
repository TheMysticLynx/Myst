//
// Created by Kaiden Howard on 10/28/22.
//
#ifndef MYST_ENTRYPOINT_H
#define MYST_ENTRYPOINT_H

#include "pch.h"
#include "Core.h"
#include "Application.h"
#include "Log.h"

#ifdef MYST_PLATFORM_MAC

int main() {
    Myst::Log::Init();

    auto app = Myst::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif

#endif //MYST_ENTRYPOINT_H