#pragma once

#include "Shotgun/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Shotgun {

	class OpenGlContext : public GraphicsContext
	{
	public:
		OpenGlContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_windowHandle;
	};
}