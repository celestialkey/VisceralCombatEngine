#pragma once

#include "RendererAPI.h"

namespace VCE {
	class RenderCommand {
	public:
		inline static void SetClearColor(const glm::vec4& clearColor) {
			s_RendererAPI->SetClearColor(clearColor);
		}
		inline static void Clear() {
			s_RendererAPI->Clear();
		}
		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray) {
			s_RendererAPI->DrawIndexed(vertexArray);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}