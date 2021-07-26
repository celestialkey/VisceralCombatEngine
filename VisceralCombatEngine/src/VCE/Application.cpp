#include "vcepch.h"
#include "Application.h"

#include "Log.h"


#include <glad/glad.h>
#include "VCE/Input.h"

namespace VCE {
	Application* Application::s_Instance = nullptr;

	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
		: m_Running(true)
	{
		VCE_CORE_ASSERT(!s_Instance, "Unable to create more than one application instance!")
		s_Instance = this;
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
		pLayer->OnAttach();
	}
	void Application::PushOverlay(Layer* pLayer) {
		m_LayerStack.PushOverlay(pLayer);
		pLayer->OnAttach();
	}
	
	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* pLayer : m_LayerStack)
				pLayer->OnUpdate();

			auto [x, y] = Input::GetMousePosition();
			VCE_CORE_WARN("MousePosition ({0},{1})", x, y);

			m_Window->OnUpdate();
		}
	}

}