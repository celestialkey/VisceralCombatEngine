#include "vcepch.h"

#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace VCE {
	OpenGLContext::OpenGLContext(GLFWwindow* pWindow)
		: m_WindowHandle(pWindow)
	{
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VCE_CORE_ASSERT(status, "Failed to initialized GLad!");

		VCE_CORE_INFO("Graphics Card:");
		VCE_CORE_INFO("\tVendor:   {0}", glGetString(GL_VENDOR));
		VCE_CORE_INFO("\tRenderer: {0}", glGetString(GL_RENDERER));
		VCE_CORE_INFO("\tVersion:  {0}", glGetString(GL_VERSION));
		
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}