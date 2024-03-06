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

#ifdef ORION_ENABLE_ASSERTS
	#define ORION_ASSERT(x, ...) { if(!(x)) { ORION_ERROR("Assertion Failed : {0}", __VA_VRGS__); __debugbreak(); } }
	#define ORION_CORE_ASSERT(x, ...) { if(!(x)) { ORION_CORE_ERROR("Assertion Failed : {0}", __VA_VRGS__); __debugbreak(); } }
#else
	#define ORION_ASSERT(x, ...);
	#define ORION_CORE_ASSERT(x, ...);
#endif

#define BIT(x) (1 << x)

#define ORION_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)