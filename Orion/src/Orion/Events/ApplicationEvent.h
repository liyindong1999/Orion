#pragma once

#include "Event.h"

using namespace std;

namespace Orion
{
	class ORION_API WindowResizeEvent : public Event
	{
	private:
		unsigned int m_Width, m_Height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		string ToString() const override
		{
			stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << " ," << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	};

	class ORION_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class ORION_API AppTickEvent : public Event
	{
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class ORION_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class ORION_API AppRenderEvent : public Event
	{
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};
}