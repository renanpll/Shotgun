#include "sgpch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Shotgun {

	Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData;

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Shader>& shader,
						  const Ref<VertexArray>& vertexArray,
						  const glm::mat4& transform,
						  const glm::vec4& color)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformFloat4("u_Color", color);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}