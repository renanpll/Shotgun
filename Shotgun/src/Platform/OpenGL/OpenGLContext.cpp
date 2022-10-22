#include "sgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Shotgun {

	OpenGlContext::OpenGlContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		SG_CORE_ASSERT(windowHandle, "Window handle is null.");
	}

	void OpenGlContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SG_CORE_ASSERT(status, "Failed to initialize Glad.");
	}
	void OpenGlContext::SwapBuffers()
	{
		glfwSwapBuffers(m_windowHandle);
	}
}