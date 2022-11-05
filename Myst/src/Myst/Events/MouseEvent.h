//
// Created by Kaiden Howard on 11/2/22.
//
#ifndef MYST_MOUSEEVENT_H
#define MYST_MOUSEEVENT_H

#include "Event.h"
#include "../pch.h"

namespace Myst {
    class MouseEvent : public Event {
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    };

    class MouseButtonEvent : public MouseEvent {
    public:
        explicit MouseButtonEvent(unsigned  int button)
                : m_Button(button) {}

        [[nodiscard]] inline unsigned int GetButton() const { return m_Button; }
        [[nodiscard]] inline std::string ToString() const override {
            std::stringstream ss;
            ss << MouseEvent::ToString() << " Button: " << m_Button;
            return ss.str();
        }
    private:
        unsigned int m_Button;
    };

    class MouseScrolledEvent : public MouseEvent {
    public:
        MouseScrolledEvent(float scrollX, float scrollY)
                : m_ScrollX(scrollX), m_ScrollY(scrollY) {}

        [[nodiscard]] inline float GetX() const { return m_ScrollX; }
        [[nodiscard]] inline float GetY() const { return m_ScrollY; }

        EVENT_CLASS_TYPE(MouseScrolled)
    private:
        float m_ScrollX, m_ScrollY;
    };

    class MouseMovedEvent : public MouseEvent {
    public:
        MouseMovedEvent(float mouseX, float mouseY)
        : m_MouseX(mouseX), m_MouseY(mouseY) {}

        [[nodiscard]] inline float GetX() const { return m_MouseX; }
        [[nodiscard]] inline float GetY() const { return m_MouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
    private:
        float m_MouseX, m_MouseY;
    };

    class MouseButtonDown : public MouseButtonEvent {
    public:
        explicit MouseButtonDown(unsigned int button, bool repeat)
        : MouseButtonEvent(button), m_Repeat(repeat){}
        [[nodiscard]] inline bool GetRepeat() const { return m_Repeat; }
        EVENT_CLASS_TYPE(MouseButtonDown)
    private:
        bool m_Repeat;
    };

    class MouseButtonUp : public MouseButtonEvent {
    public:
        explicit MouseButtonUp(unsigned int button)
                : MouseButtonEvent(button){}
        EVENT_CLASS_TYPE(MouseButtonUp)
    };
}

#endif //MYST_MOUSEEVENT_H
