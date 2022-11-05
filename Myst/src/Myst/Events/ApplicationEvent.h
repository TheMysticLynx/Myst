//
// Created by Kaiden Howard on 11/2/22.
//

#ifndef MYST_APPLICATIONEVENT_H
#define MYST_APPLICATIONEVENT_H

#include "Event.h"

namespace Myst {
    class WindowResizeEvent : public Event{
    public:
        WindowResizeEvent(int width, int height)
        : m_Width(width), m_Height(height) { };
        [[nodiscard]] inline unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] inline unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << Event::ToString() << " " << m_Width << " " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        EVENT_CLASS_TYPE(WindowResize)
    private:
        unsigned int m_Width, m_Height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent()= default;
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        EVENT_CLASS_TYPE(WindowClose)
    };
}

#endif //MYST_APPLICATIONEVENT_H
