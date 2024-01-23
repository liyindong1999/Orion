#pragma once


#ifdef ORION_PLATFORM_WINDOWS

extern Orion::Application* Orion::CreateApplication();

int main(int argc, char** argv)
{
	Orion::Log::Init();
	ORION_CORE_WARN("log init");
	ORION_CORE_INFO("Hello");
	auto app = Orion::CreateApplication();
	app->Run();
	delete app;
}


#endif // ORION_PLATFORM_WINDOWS
