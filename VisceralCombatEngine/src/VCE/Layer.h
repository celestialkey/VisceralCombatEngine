#pragma once
#include "VCE/Core.h"
#include "VCE/Events/Event.h"
#include "VCE/Core/Timestep.h"

namespace VCE {
	class VCE_API Layer
	{
	public:
		Layer(const std::string& layerName = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate(Timestep ts) {};
		virtual void OnImGuiRender() {};
		virtual void OnEvent(Event& e) {};
		
		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

