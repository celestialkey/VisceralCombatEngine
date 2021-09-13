#include "vcepch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace VCE {
	Shader* Shader::Create(const std::string& vSrc, const std::string& fSrc) {
		switch (Renderer::GetAPI()) {
			case RendererAPI::API::None:	VCE_ASSERT(false, "RenderAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL:	return new OpenGLShader(vSrc, fSrc);
		}

		VCE_ASSERT(false, "Unknown Render API requested!");
		return nullptr;
	}
}