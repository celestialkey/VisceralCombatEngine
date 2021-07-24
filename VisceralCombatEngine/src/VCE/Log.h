#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace VisceralCombatEngine {
	class VCE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return m_ApplicationLogger; };

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ApplicationLogger;
	};

}


// Used by the VisceralCombatEngine
#define VCE_CORE_TRACE(...)    ::VisceralCombatEngine::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define VCE_CORE_DEBUG(...)    ::VisceralCombatEngine::Log::GetCoreLogger()->debug(__VA_ARGS__);
#define VCE_CORE_INFO(...)     ::VisceralCombatEngine::Log::GetCoreLogger()->info(__VA_ARGS__);
#define VCE_CORE_WARN(...)     ::VisceralCombatEngine::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define VCE_CORE_ERROR(...)    ::VisceralCombatEngine::Log::GetCoreLogger()->error(__VA_ARGS__);
#define VCE_CORE_CRITICAL(...) ::VisceralCombatEngine::Log::GetCoreLogger()->critical(__VA_ARGS__);


// USed by client
#define VCE_TRACE(...)    ::VisceralCombatEngine::Log::GetAppLogger()->trace(__VA_ARGS__);
#define VCE_DEBUG(...)    ::VisceralCombatEngine::Log::GetAppLogger()->debug(__VA_ARGS__);
#define VCE_INFO(...)     ::VisceralCombatEngine::Log::GetAppLogger()->info(__VA_ARGS__);
#define VCE_WARN(...)     ::VisceralCombatEngine::Log::GetAppLogger()->warn(__VA_ARGS__);
#define VCE_ERROR(...)    ::VisceralCombatEngine::Log::GetAppLogger()->error(__VA_ARGS__);
#define VCE_CRITICAL(...) ::VisceralCombatEngine::Log::GetAppLogger()->critical(__VA_ARGS__);