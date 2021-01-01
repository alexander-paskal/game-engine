#pragma once

#include "Event.h"

#include <sstream>

namespace Hazel {
	class HAZEL_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput); // bitwise union of the two categories
			// macro for implementing the categories

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {} // Protected constructor, stores m_KeyCode value

		int m_KeyCode;
	};


	class HAZEL_API	KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
		: KeyEvent(keycode), m_RepeatCount(repeatCount) {}  // calls teh constructor for KeyEvent, and also stores the m_RepeatCount value

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};


	class HAZEL_API	KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}  // calls teh constructor for KeyEvent, and also stores the m_RepeatCount value

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}