#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

using namespace std;

namespace Orion 
{
	class ORION_API Application
	{
	private:
		unique_ptr<Window> m_Window;
		bool m_Running = true;

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		bool OnWindowCloseEvent(WindowCloseEvent& e);
	};

	//To be defined in client
	Application* CreateApplication();
}


