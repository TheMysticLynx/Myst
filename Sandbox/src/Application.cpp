//
// Created by Kaiden Howard on 10/28/22.
//
#include "../../Myst/src/Myst.h"
#include <iostream>

class Sandbox : public Myst::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

Myst::Application *Myst::CreateApplication() {
    return new Sandbox();
}