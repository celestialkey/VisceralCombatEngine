#include "vcepch.h"
#include "Application.h"

 #include "Log.h"

#include "VCE/Renderer/Renderer.h"

#include "VCE/Input.h"
#include "VCE/Renderer/Shader.h"

#include <GLFW/glfw3.h>

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

		m_ImGuiLayer =new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
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
			float _time = (float)glfwGetTime();
			Timestep timestep = _time - m_LastFrameTime;
			m_LastFrameTime = _time;
			 
			for (Layer* pLayer : m_LayerStack)
				pLayer->OnUpdate(timestep);
			
			m_ImGuiLayer->Begin();
				for (Layer* pLayer : m_LayerStack)
					pLayer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

}