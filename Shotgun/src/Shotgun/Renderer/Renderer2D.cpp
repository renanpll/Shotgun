#include "sgpch.h"
#include "Renderer2D.h"

#include "RenderCommand.h"
#include "Shader.h"
#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Shotgun {

	struct Renderer2DStorage
	{
		Ref<VertexArray> quadVertexArray;
		Ref<Shader> flatColorShader;
	};

	static Renderer2DStorage* s_Data;
	
	void Renderer2D::Init()
	{
		s_Data = new Renderer2DStorage();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		s_Data->quadVertexArray = Shotgun::VertexArray::Create();

		Ref<VertexBuffer> vertexBuffer;
		vertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		BufferLayout squareLayout = {
			{ ShaderDataType::Float3, "a_Position" },
		};

		vertexBuffer->SetLayout(squareLayout);

		s_Data->quadVertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int squareIndices[6] = { 0,1,2,2,3,0 };
		Ref<IndexBuffer> squareIndexBuffer;
		squareIndexBuffer = IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		s_Data->quadVertexArray->SetIndexBuffer(squareIndexBuffer);

		s_Data->flatColorShader = Shader::Create("assets/shaders/FlatColor.glsl");
	}

	void Renderer2D::Shutdown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->flatColorShader)->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->flatColorShader)->UploadUniformMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->flatColorShader)->UploadUniformMat4("u_Transform", glm::mat4(1.f));
	}

	void Renderer2D::EndScene()
	{
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->flatColorShader)->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->flatColorShader)->UploadUniformFloat4("u_Color", color);

		s_Data->quadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->quadVertexArray);
	}

}