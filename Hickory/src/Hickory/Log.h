#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hickory {

	class HCK_API Log
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
// Core log macros
#define HCK_CORE_TRACE(...)    ::Hickory::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HCK_CORE_INFO(...)     ::Hickory::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HCK_CORE_WARN(...)     ::Hickory::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HCK_CORE_ERROR(...)    ::Hickory::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HCK_CORE_FATAL(...)    ::Hickory::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HCK_TRACE(...)	      ::Hickory::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HCK_INFO(...)	      ::Hickory::Log::GetClientLogger()->info(__VA_ARGS__)
#define HCK_WARN(...)	      ::Hickory::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HCK_ERROR(...)	      ::Hickory::Log::GetClientLogger()->error(__VA_ARGS__)
#define HCK_FATAL(...)	      ::Hickory::Log::GetClientLogger()->fatal(__VA_ARGS__)

