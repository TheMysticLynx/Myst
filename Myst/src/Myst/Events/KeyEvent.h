//
// Created by Kaiden Howard on 11/2/22.
//


#ifndef MYST_KEYEVENT_H
#define MYST_KEYEVENT_H
#include "../pch.h"
#include "Event.h"

namespace Myst {
    class KeyEvent : public Event {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }
        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << Event::ToString() << " " << m_KeyCode;
            return ss.str();
        }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
        : m_KeyCode(keycode) {
        }

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, bool isRepeat):
                KeyEvent(keycode), m_IsRepeat(isRepeat) {}
        [[nodiscard]] inline bool IsRepeat() const { return m_IsRepeat; }
        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << KeyEvent::ToString() << " Repeat: " << m_IsRepeat;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyDown)
    private:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        explicit KeyReleasedEvent(int keycode):
                KeyEvent(keycode)
                {}
        EVENT_CLASS_TYPE(KeyUp)
    };
}

#endif //MYST_KEYEVENT_H
