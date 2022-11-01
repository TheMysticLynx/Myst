//
// Created by Kaiden Howard on 10/28/22.
//
#include <Myst/src/Myst.h>
#include <iostream>

class Sandbox : public Myst::Application {
public:
    Sandbox() {
        Myst::Log::GetClientLogger()->info("Logging from application!");
    }

    ~Sandbox() {
        //Ignored
    }
};

Myst::Application *Myst::CreateApplication() {
    return new Sandbox();
}