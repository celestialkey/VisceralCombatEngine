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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		
		void Begin();
		void End();


	private:
		float m_Time = 0.0f;
	};

}