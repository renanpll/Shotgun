#pragma once

#include "Shotgun/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Shotgun {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_windowHandle;
	};
}