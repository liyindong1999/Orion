#pragma once

#include "Orion/Core.h"

using namespace std;

namespace Orion
{
	//当前的事件系统是即时性的，没有buffer缓冲

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, //窗口事件
		AppTick, AppUpdate, AppRender, //应用事件
		KeyPressed, KeyReleased, //按键事件
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled //鼠标事件
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication     = BIT(0),
		EventCategoryInput			 = BIT(1),
		EventCategoryKeyboard		 = BIT(2),
		EventCategoryMouse			 = BIT(3),
		EventCategoryMouseButton	 = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								   virtual EventType GetEventType() const override { return GetStaticType(); }\
								   virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(Category) virtual int GetCategoryFlags() const override { return Category; }
	
	class ORION_API Event
	{
		friend class EventDispatcher;

	public:
		bool m_Handled = false;

		virtual EventType GetEventType() const = 0; //获取事件类型
		virtual const char* GetName() const = 0; //获取名称
		virtual int GetCategoryFlags() const = 0; //获取事件类别标志
		virtual string ToString() const { return GetName(); }

		//判断当前类事件是否属于某一类型的事件
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	//事件分发器
	class EventDispatcher
	{
		template<typename T>
		using EventFn = function<bool(T&)>;

	private:
		Event& m_Event;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};

	inline ostream& operator<<(ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}