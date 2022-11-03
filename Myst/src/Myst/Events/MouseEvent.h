//
// Created by Kaiden Howard on 11/2/22.
//

#include "Event.h"

#ifndef MYST_MOUSEEVENT_H
#define MYST_MOUSEEVENT_H

namespace Myst {
    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float mouseX, float mouseY)
        : m_MouseX(mouseX), m_MouseY(mouseY) {}

        [[nodiscard]] inline float GetX() const { return m_MouseX; }
        [[nodiscard]] inline float GetY() const { return m_MouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    private:
        float m_MouseX, m_MouseY;
    };
}

#endif //MYST_MOUSEEVENT_H
