#include "OrionPCH.h"

#include "Application.h"
#include "Log.h"

using namespace std;

namespace Orion 
{

	#define BIND_EVENT_FN(x) bind(&Application::x, this, placeholders::_1)
	
	Application::Application()
	{
		m_Window = unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
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

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));
		ORION_CORE_INFO("{0}", e);
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

