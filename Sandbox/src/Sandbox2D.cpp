#include "Sandbox2D.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

namespace Shotgun {

	Sandbox2D::Sandbox2D()
		:Layer("Sandbox2D"), m_CameraController(1280.f / 720.f, true)
	{
	}

	void Sandbox2D::OnAttach()
	{
		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		m_VertexArray = Shotgun::VertexArray::Create();

		Shotgun::Ref<Shotgun::VertexBuffer> vertexBuffer;
		vertexBuffer = Shotgun::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		Shotgun::BufferLayout squareLayout = {
			{ Shotgun::ShaderDataType::Float3, "a_Position" },
		};

		vertexBuffer->SetLayout(squareLayout);

		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int squareIndices[6] = { 0,1,2,2,3,0 };
		Shotgun::Ref<Shotgun::IndexBuffer> squareIndexBuffer;
		squareIndexBuffer = Shotgun::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		m_VertexArray->SetIndexBuffer(squareIndexBuffer);

		m_FlatColorShader = Shotgun::Shader::Create("assets/shaders/FlatColor.glsl");

	}

	void Sandbox2D::OnDetach()
	{
	}

	void Sandbox2D::OnUpdate(Timestep ts)
	{
		//Update
		m_CameraController.OnUpdate(ts);

		//Render
		Shotgun::RenderCommand::SetClearColor({ 0.1F, 0.1F, 0.1F, 1 });
		Shotgun::RenderCommand::Clear();

		Shotgun::Renderer::BeginScene(m_CameraController.GetCamera());

		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);


		Shotgun::Renderer::Submit(m_FlatColorShader, m_VertexArray, glm::scale(glm::mat4(1.f), glm::vec3(1.5f)));

		Shotgun::Renderer::EndScene();
	}

	void Sandbox2D::OnImGuiRender()
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void Sandbox2D::OnEvent(Event& e)
	{
		m_CameraController.OnEvent(e);
	}

}