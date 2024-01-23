#pragma once
#include "Core.h"

namespace Orion 
{
	class ORION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}


