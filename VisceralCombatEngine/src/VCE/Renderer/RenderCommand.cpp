#include "vcepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace VCE {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}