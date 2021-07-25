#pragma once
#include "VCE/Core.h"
#include "VCE/Events/Event.h"

namespace VCE {
	class VCE_API Layer
	{
	public:
		Layer(const std::string& layerName = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};
		
		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

