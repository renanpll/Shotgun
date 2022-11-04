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
		m_CheckerboardTexture = Shotgun::Texture2D::Create("assets/textures/Checkerboard.png");
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

		Shotgun::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Shotgun::Renderer2D::DrawQuad({ -1.f, 0.f }, { 1.0f, 1.0f }, m_SquareColor);
		Shotgun::Renderer2D::DrawQuad({ 0.f, 0.f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);


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