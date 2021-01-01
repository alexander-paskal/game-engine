#pragma once

#include "Hazel/Core.h"

#include <string>
#include <functional>

namespace Hazel {


	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None=0,
		EventCategoryApplication    =BIT(0),  // These are for filtering events
		EventCategoryInput          =BIT(1),
		EventCategoryKeyboard       =BIT(2),  // BIT is a macro defined in Core.h
		EventCategoryMouse          =BIT(3),
		EventCategoryMouseButton    =BIT(4)
	};

	/// These macros are implementing the virtual functions found in all of the things

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;  }\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}



	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;  // pure virtual means that they must be implemented
		virtual const char* GetName() const = 0;  // This is a pointer to a constant?
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;  // This is probably set up to use bitwise comparison for identifying categorys
		}
	protected:
		bool m_Handled = false;  // so I guess the EventDispatcher will change this flag
	};




	class HAZEL_API EventDispatcher
	{
		template<typename T> // ?????
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType == T::GetStaticType())
			{
				m_Event.m_EventHandled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString(); // just an output stream I guess
	}

}