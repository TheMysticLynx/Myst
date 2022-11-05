//
// Created by Kaiden Howard on 11/1/22.
//

#include <string>
#include "../Core.h"

#ifndef MYST_EVENT_H
#define MYST_EVENT_H

enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus,
    KeyDown, KeyUp,
    MouseMoved, MouseScrolled, MouseButtonDown, MouseButtonUp
};

enum EventCategory {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
virtual EventType GetEventType() const override { return GetStaticType(); }                                  \
virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

namespace Myst {
    MYST_API class Event{
        friend class EventDispatcher;
    public:
        virtual ~Event()= default;
        [[nodiscard]]virtual EventType GetEventType() const = 0;
        [[nodiscard]]virtual const char* GetName() const = 0;
        [[nodiscard]]virtual int GetCategoryFlags() const = 0;
        [[nodiscard]]virtual std::string ToString() const { return GetName(); }
        [[nodiscard]] inline bool IsInCategory(EventCategory eventCategory) const {
            return GetCategoryFlags() & eventCategory;
        }
    protected:
        bool m_Handled = false;
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        explicit EventDispatcher(Event& event)
        : m_Event(event) {}

        template<class T>
        bool Dispatch(EventFn<T> func) {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    protected:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& ostream, Event& event) {
        return ostream << event.ToString();
    }
}


#endif //MYST_EVENT_H
