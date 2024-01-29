#pragma once

#ifdef ORION_PLATFORM_WINDOWS
	#ifdef ORION_BUILD_DLL
		#define ORION_API _declspec(dllexport)
	#else
		#define ORION_API _declspec(dllimport)
	#endif
#else
	#error Orion only support windows
#endif

#define BIT(x) (1 << x)