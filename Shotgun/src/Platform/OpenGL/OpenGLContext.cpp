#include "sgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Shotgun {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		SG_CORE_ASSERT(windowHandle, "Window handle is null.");
	}

	void OpenGLContext::Init()
	{
		SG_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SG_CORE_ASSERT(status, "Failed to initialize Glad.");

		SG_CORE_INFO("OpenGL Info:");
		SG_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		SG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		SG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		SG_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Shotgun requires at least OpenGL version 4.5!");

	}
	void OpenGLContext::SwapBuffers()
	{
		SG_PROFILE_FUNCTION();

		glfwSwapBuffers(m_windowHandle);
	}
}
