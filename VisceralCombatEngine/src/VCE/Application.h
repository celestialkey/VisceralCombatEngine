#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "VCE/Events/ApplicationEvent.h"

#include "Window.h"

namespace VCE {
	class VCE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::shared_ptr<Window> m_Window;
		bool m_Running;
	};

	// To be defined in client
	Application* CreateApplication();
}
