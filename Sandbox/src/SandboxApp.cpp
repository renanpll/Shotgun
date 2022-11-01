#include "Shotgun.h"

#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"


class ExampleLayer : public Shotgun::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.f / 720.f, true)
	{

		m_VertexArray = Shotgun::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Shotgun::BufferLayout layout = {
			{ Shotgun::ShaderDataType::Float3, "a_Position" },
			{ Shotgun::ShaderDataType::Float4, "a_Color" }
		};

		Shotgun::Ref<Shotgun::VertexBuffer> vertexBuffer;
		vertexBuffer = Shotgun::VertexBuffer::Create(vertices, sizeof(vertices));

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0,1,2 };
		Shotgun::Ref<Shotgun::IndexBuffer> indexBuffer;
		indexBuffer = Shotgun::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Shotgun::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Shotgun::Ref<Shotgun::VertexBuffer> squareVB;
		squareVB = Shotgun::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		Shotgun::BufferLayout squareLayout = {
			{ Shotgun::ShaderDataType::Float3, "a_Position" },
			{ Shotgun::ShaderDataType::Float2, "a_TexCoord" }
		};
		squareVB->SetLayout(squareLayout);

		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0,1,2,2,3,0 };
		Shotgun::Ref<Shotgun::IndexBuffer> squareIndexBuffer;
		squareIndexBuffer = Shotgun::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

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

		m_Shader = Shotgun::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

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

		m_FlatColorShader = Shotgun::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Shotgun::Texture2D::Create("assets/textures/Checkerboard.png");
		m_LogoTexture = Shotgun::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}



	void OnUpdate(Shotgun::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);


		//Render
		Shotgun::RenderCommand::SetClearColor({ 0.1F, 0.1F, 0.1F, 1 });
		Shotgun::RenderCommand::Clear();

		Shotgun::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Shotgun::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{		
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.f), pos) * scale;
				Shotgun::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
				
			}
		}
		
		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Shotgun::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.f), glm::vec3(1.5f)));
		m_LogoTexture->Bind();
		Shotgun::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.f), glm::vec3(1.5f)));
		Shotgun::Renderer::Submit(m_Shader, m_VertexArray);
		
		Shotgun::Renderer::EndScene();

	}

	void OnEvent(Shotgun::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

private:

	Shotgun::Ref<Shotgun::Shader> m_Shader;
	Shotgun::Ref<Shotgun::VertexArray> m_VertexArray;

	Shotgun::Ref<Shotgun::Shader> m_FlatColorShader;
	Shotgun::Ref<Shotgun::VertexArray> m_SquareVA;
	Shotgun::Ref<Shotgun::Texture2D> m_Texture;
	Shotgun::Ref<Shotgun::Texture2D> m_LogoTexture;

	Shotgun::ShaderLibrary m_ShaderLibrary;

	Shotgun::OrthographicCameraController m_CameraController;
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