#pragma once

#include "Event.h"

#include <sstream>


namespace Hazel
{
	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x_pos, float y_pos)
			: m_MouseX(x_pos), m_MouseY(y_pos) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: x = " << m_MouseX << ", y = " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)  // this macro returns all the typing information we need
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		
	private:
		float m_MouseX, m_MouseY;
	};

	//////////////////////////////////////////////////////////////////////////

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: x = " << m_XOffset << ", y = " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)  // this macro returns all the typing information we need
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


	private:
		float m_XOffset, m_YOffset;
	};

	////////////////////////////////////////////

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;

	};

	//////////////////////////////////////

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	//////////////////////////////////////

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}