#include "OrionPCH.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Orion 
{
	Application::Application()
	{
		m_Window = unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}

