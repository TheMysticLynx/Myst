//
// Created by Kaiden Howard on 11/2/22.
//

#include "Event.h"

#ifndef MYST_KEYEVENT_H
#define MYST_KEYEVENT_H

namespace Myst {
    class KeyEvent : public Event {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
        : m_KeyCode(keycode) {
        }

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount):
                KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        [[nodiscard]] inline int GetRepeatCount() const { return m_RepeatCount; }

        EVENT_CLASS_TYPE(KeyDown)
    private:
        int m_RepeatCount;
    };
}

#endif //MYST_KEYEVENT_H
