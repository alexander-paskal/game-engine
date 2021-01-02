#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {
	class HAZEL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		// I guess here we are declaring them as attributes? shared pointers, whatever that means -- no, these are the functions that return those attributes
		// That little {} thing at the end is literally just to one-line hte code but we are really declaring a function
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;  // here we are defining them as attributes
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// The benefit of having the logs be macros is that, in distribution builds, you can just redefine the macros
// to do nothing, saving performance
// Core macros

#define HZ_CORE_TRACE(...)     ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)      ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)      ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)     ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)     ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client macros

#define HZ_INFO(...)	       ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	       ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_TRACE(...)	       ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_ERROR(...)	       ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)	       ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)