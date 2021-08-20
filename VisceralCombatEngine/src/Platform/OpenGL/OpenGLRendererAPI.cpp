#include "vcepch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace VCE {
	void OpenGLRendererAPI::SetClearColor(const glm::vec4& clearColor) {
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	}
	void OpenGLRendererAPI::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertextArray) {
		glDrawElements(GL_TRIANGLES, vertextArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}