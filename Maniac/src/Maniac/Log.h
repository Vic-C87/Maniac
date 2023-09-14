#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Maniac
{
	class MANIAC_API Log
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
#define MN_CORE_TRACE(...)      ::Maniac::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MN_CORE_INFO(...)       ::Maniac::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MN_CORE_WARN(...)       ::Maniac::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MN_CORE_ERROR(...)      ::Maniac::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MN_CORE_FATAL(...)      ::Maniac::Log::GetCoreLogger()->critical(__VA_ARGS__)
							    
//Client log macros						    
#define MN_TRACE(...)    ::Maniac::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MN_INFO(...)     ::Maniac::Log::GetClientLogger()->info(__VA_ARGS__)
#define MN_WARN(...)     ::Maniac::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MN_ERROR(...)    ::Maniac::Log::GetClientLogger()->error(__VA_ARGS__)
#define MN_FATAL(...)    ::Maniac::Log::GetClientLogger()->critical(__VA_ARGS__)

