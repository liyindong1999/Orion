#pragma once

#include "Event.h"

using namespace std;

namespace Orion
{
	//����ƶ��¼�
	class ORION_API MouseMovedEvent : public Event
	{
	private:
		float m_MouseX, m_MouseY;

	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)	
	};

	//�������¼�
	class ORION_API MouseScrolledEvent : public Event
	{
	private:
		float m_XOffset, m_YOffset;

	public:
		MouseScrolledEvent(float XOffset, float YOffset) : m_XOffset(XOffset), m_YOffset(YOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	//��갴���¼�
	class ORION_API MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;

	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class ORION_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ORION_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}