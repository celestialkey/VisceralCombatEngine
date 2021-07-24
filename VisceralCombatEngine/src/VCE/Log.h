#pragma once

#include "Core.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace VCE {
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


// Used by the VCE
#define VCE_CORE_TRACE(...)    ::VCE::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define VCE_CORE_INFO(...)     ::VCE::Log::GetCoreLogger()->info(__VA_ARGS__);
#define VCE_CORE_WARN(...)     ::VCE::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define VCE_CORE_ERROR(...)    ::VCE::Log::GetCoreLogger()->error(__VA_ARGS__);
#define VCE_CORE_CRITICAL(...) ::VCE::Log::GetCoreLogger()->critical(__VA_ARGS__);


// USed by client
#define VCE_TRACE(...)         ::VCE::Log::GetAppLogger()->trace(__VA_ARGS__);
#define VCE_INFO(...)          ::VCE::Log::GetAppLogger()->info(__VA_ARGS__);
#define VCE_WARN(...)          ::VCE::Log::GetAppLogger()->warn(__VA_ARGS__);
#define VCE_ERROR(...)         ::VCE::Log::GetAppLogger()->error(__VA_ARGS__);
#define VCE_CRITICAL(...)      ::VCE::Log::GetAppLogger()->critical(__VA_ARGS__);