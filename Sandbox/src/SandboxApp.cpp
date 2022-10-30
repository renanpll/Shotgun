#include "Shotgun.h"

#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class ExampleLayer : public Shotgun::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_CameraRotation(0.0f)
	{

		m_VertexArray.reset(Shotgun::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Shotgun::BufferLayout layout = {
			{ Shotgun::ShaderDataType::Float3, "a_Position" },
			{ Shotgun::ShaderDataType::Float4, "a_Color" }
		};

		std::shared_ptr<Shotgun::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Shotgun::VertexBuffer::Create(vertices, sizeof(vertices)));

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0,1,2 };
		std::shared_ptr<Shotgun::IndexBuffer> indexBuffer;
		indexBuffer.reset(Shotgun::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Shotgun::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<Shotgun::VertexBuffer> squareVB;
		squareVB.reset(Shotgun::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		Shotgun::BufferLayout squareLayout = { { Shotgun::ShaderDataType::Float3, "a_Position" } };
		squareVB->SetLayout(squareLayout);

		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0,1,2,2,3,0 };
		std::shared_ptr<Shotgun::IndexBuffer> squareIndexBuffer;
		squareIndexBuffer.reset(Shotgun::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

		m_SquareVA->SetIndexBuffer(squareIndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Shotgun::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			uniform vec4 u_Color;

			in vec3 v_Position;

			void main()
			{
				color = u_Color;
			}
		)";

		m_FlatColorShader.reset(Shotgun::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));
	}

	void OnUpdate(Shotgun::Timestep ts) override
	{

		if (Shotgun::Input::IsKeyPressed(SG_KEY_LEFT) || Shotgun::Input::IsKeyPressed(SG_KEY_A))
			m_CameraPosition.x += m_CameraSpeed * ts;
		else if (Shotgun::Input::IsKeyPressed(SG_KEY_RIGHT) || Shotgun::Input::IsKeyPressed(SG_KEY_D))
			m_CameraPosition.x -= m_CameraSpeed * ts;

		if (Shotgun::Input::IsKeyPressed(SG_KEY_UP) || Shotgun::Input::IsKeyPressed(SG_KEY_W))
			m_CameraPosition.y -= m_CameraSpeed * ts;
		else if (Shotgun::Input::IsKeyPressed(SG_KEY_DOWN) || Shotgun::Input::IsKeyPressed(SG_KEY_S))
			m_CameraPosition.y += m_CameraSpeed * ts;

		if (Shotgun::Input::IsKeyPressed(SG_KEY_Q))
			m_CameraRotation -= m_CameraSpeed * 10 * ts;
		else if (Shotgun::Input::IsKeyPressed(SG_KEY_E))
			m_CameraRotation += m_CameraSpeed * 10 * ts;

		if (Shotgun::Input::IsKeyPressed(SG_KEY_SPACE))
		{
			m_CameraPosition = glm::vec3(0.0f);
			m_CameraRotation = 0.0f;
		}

		Shotgun::RenderCommand::SetClearColor({ 0.1F, 0.1F, 0.1F, 1 });
		Shotgun::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Shotgun::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.f), glm::vec3(0.1f));

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{		
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.f), pos) * scale;
				Shotgun::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform, m_SquareColor);
				
			}
		}
		
		Shotgun::Renderer::Submit(m_Shader, m_VertexArray);
		Shotgun::Renderer::EndScene();

	}

	void OnEvent(Shotgun::Event& event) override
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

private:

	std::shared_ptr<Shotgun::Shader> m_Shader;
	std::shared_ptr<Shotgun::VertexArray> m_VertexArray;

	std::shared_ptr<Shotgun::Shader> m_FlatColorShader;
	std::shared_ptr<Shotgun::VertexArray> m_SquareVA;

	Shotgun::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraRotation;
	float m_CameraSpeed = 3.f;
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};

class Sandbox : public Shotgun::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}

};

Shotgun::Application* Shotgun::CreateApplication()
{
	return new Sandbox();
}