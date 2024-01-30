#pragma once

#include "Core.h"
#include "Events/Event.h"
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
	};

	//To be defined in client
	Application* CreateApplication();
}


