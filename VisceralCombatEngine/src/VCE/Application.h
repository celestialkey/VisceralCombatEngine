#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "VCE/Events/ApplicationEvent.h"


namespace VCE {
	class VCE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* pLayer);
		void PushOverlay(Layer* pLayer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::shared_ptr<Window> m_Window;
		bool m_Running;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}
