#pragma once

#include "VCE/Layer.h"
#include "VCE/Events/MouseEvent.h"
#include "VCE/Events/KeyEvent.h"
#include "VCE/Events/ApplicationEvent.h"

namespace VCE {
	class VCE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		
		bool OnWindowResizedEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;
	};

}