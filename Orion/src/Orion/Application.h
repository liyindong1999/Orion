#pragma once

#include "Orion/Core.h"
#include "Orion/Events/Event.h"
#include "Orion/Events/ApplicationEvent.h"
#include "Orion/Window.h"
#include "Orion/LayerStack.h"

using namespace std;

namespace Orion 
{
	class ORION_API Application
	{
	private:
		unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		bool OnWindowCloseEvent(WindowCloseEvent& e);

	private:
		static Application* s_Instance;

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	};

	//To be defined in client
	Application* CreateApplication();
}


