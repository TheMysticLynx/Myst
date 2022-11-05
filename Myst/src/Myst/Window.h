//
// Created by Kaiden Howard on 11/2/22.
//
#pragma once
#include <utility>

#include "pch.h"
#include "Events/Event.h"

namespace Myst {
    struct WindowProps {
        std::string Name;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(std::string name = "Myst Engine", unsigned int width = 1024, unsigned int height = 720)
        :Name(std::move(name)), Width(width), Height(height){}
    };

    class MYST_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        explicit Window(const WindowProps& windowProps) {};

        virtual ~Window() = default;
        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        // Window attribute
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}