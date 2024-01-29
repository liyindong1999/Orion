#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Orion 
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ORION_TRACE(e);
		while (true);
	}
}

