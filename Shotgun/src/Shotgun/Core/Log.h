#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Shotgun {
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define SG_CORE_TRACE(...)		::Shotgun::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SG_CORE_INFO(...)		::Shotgun::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SG_CORE_WARN(...)		::Shotgun::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SG_CORE_ERROR(...)		::Shotgun::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SG_CORE_CRITICAL(...)	::Shotgun::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define SG_TRACE(...)			::Shotgun::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SG_INFO(...)			::Shotgun::Log::GetClientLogger()->info(__VA_ARGS__)
#define SG_WARN(...)			::Shotgun::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SG_ERROR(...)			::Shotgun::Log::GetClientLogger()->error(__VA_ARGS__)
#define SG_CRITICAL(...)		::Shotgun::Log::GetClientLogger()->critical(__VA_ARGS__)
