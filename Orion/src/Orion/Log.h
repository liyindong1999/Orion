#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

using namespace std;

namespace Orion
{
	class ORION_API Log
	{
	public:
		static void Init();

		inline static shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; } 
		inline static shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:
		static shared_ptr<spdlog::logger> CoreLogger;
		static shared_ptr<spdlog::logger> ClientLogger;
	};
}

// log macros
#define ORION_CORE_TRACE(...) ::Orion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ORION_CORE_INFO(...)  ::Orion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORION_CORE_WARN(...)  ::Orion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORION_CORE_ERROR(...) ::Orion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORION_CORE_FATAL(...) ::Orion::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ORION_TRACE(...)	  ::Orion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ORION_INFO(...)		  ::Orion::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORION_WARN(...)		  ::Orion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ORION_ERROR(...)	  ::Orion::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORION_FATAL(...)	  ::Orion::Log::GetClientLogger()->fatal(__VA_ARGS__)
