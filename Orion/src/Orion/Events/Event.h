#pragma once

#include "Orion/Core.h"

using namespace std;

namespace Orion
{
	//��ǰ���¼�ϵͳ�Ǽ�ʱ�Եģ�û��buffer����

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, //�����¼�
		AppTick, AppUpdate, AppRender, //Ӧ���¼�
		KeyPressed, KeyReleased, //�����¼�
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled //����¼�
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

		virtual EventType GetEventType() const = 0; //��ȡ�¼�����
		virtual const char* GetName() const = 0; //��ȡ����
		virtual int GetCategoryFlags() const = 0; //��ȡ�¼�����־
		virtual string ToString() const { return GetName(); }

		//�жϵ�ǰ���¼��Ƿ�����ĳһ���͵��¼�
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	//�¼��ַ���
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