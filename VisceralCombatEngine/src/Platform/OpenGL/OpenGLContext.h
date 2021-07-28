#pragma once

#include <VCE/Renderer/RenderContext.h>

struct GLFWwindow;

namespace VCE {
	class OpenGLContext : public RenderContext
	{
	public:
		OpenGLContext(GLFWwindow* pWindow);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}