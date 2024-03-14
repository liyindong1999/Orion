#include <OrionPCH.h>
#include "Orion.h"


class ExampleLayer : public Orion::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override 
	{ 
		ORION_INFO("ExampleLayr::Update"); 
		if (Orion::Input::IsKeyPressed(ORION_KEY_TAB))
		{
			ORION_INFO("tab is pressed");
		}
	}
	void OnEvent(Orion::Event& event) override { ORION_TRACE("{0}", event); }
};



class Sandbox : public Orion::Application
{
public:
	Sandbox() 
	{ 
		PushLayer(new ExampleLayer());
		PushOverlay(new Orion::ImGuiLayer());
	}
	~Sandbox() {}
};

Orion::Application* Orion::CreateApplication()
{
	return new Sandbox();
}