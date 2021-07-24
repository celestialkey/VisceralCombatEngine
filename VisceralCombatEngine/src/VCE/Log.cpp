#include "Log.h"


namespace VisceralCombatEngine {

	std::shared_ptr<spdlog::logger> Log::m_ApplicationLogger;
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		m_CoreLogger = spdlog::stdout_color_mt("VCE");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ApplicationLogger = spdlog::stdout_color_mt("APP");
		m_ApplicationLogger->set_level(spdlog::level::trace);
		
	}

}