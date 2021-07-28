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
		m_ImGuiLayer =new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);
		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float verts[3 * 3] = {
			-0.5f, -0.5f, -0.0f,
			0.5f, -0.5f, -0.0f,
			0.0f, 0.5f, -0.0f,
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);
		
		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		unsigned int indices[3]{
			0,1,2
		};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
			glClearColor(.1f, 0.1f, .1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);


			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* pLayer : m_LayerStack)
				pLayer->OnUpdate();




			m_ImGuiLayer->Begin();
			for (Layer* pLayer : m_LayerStack)
					pLayer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

}