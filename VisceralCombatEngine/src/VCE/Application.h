#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace VCE {
	class VCE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

	private:
		std::shared_ptr<Window> m_Window;
		bool m_Running;
	};

	// To be defined in client
	Application* CreateApplication();
}
