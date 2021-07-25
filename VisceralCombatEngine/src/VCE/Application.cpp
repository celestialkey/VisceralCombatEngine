#include "vcepch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace VCE {
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
		: m_Running(true)
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application() {
	
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		VCE_CORE_INFO("{0}", e);
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) {
				break;
			}
		}
	}
	void Application::PushLayer(Layer* pLayer) {
		m_LayerStack.PushLayer(pLayer);
	}
	void Application::PushOverlay(Layer* pLayer) {
		m_LayerStack.PushOverlay(pLayer);
	}
	
	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* pLayer : m_LayerStack)
				pLayer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}