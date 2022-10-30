#pragma once

#include "Shotgun/Renderer/RendererAPI.h"

namespace Shotgun {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(glm::vec4 color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}