#include "Sandbox2D.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <chrono>

namespace Shotgun {

	Sandbox2D::Sandbox2D()
		:Layer("Sandbox2D"), m_CameraController(1280.f / 720.f, true)
	{
	}

	void Sandbox2D::OnAttach()
	{
		SG_PROFILE_FUNCTION();

		m_CheckerboardTexture = Shotgun::Texture2D::Create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = Texture2D::Create("assets/textures/ChernoLogo.png");
		m_SpriteSheet = Texture2D::Create("assets/textures/RPGpack_sheet_2X.png");

		m_TextureStairs = SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
		m_TextureTree = SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, {1, 2});

	}

	void Sandbox2D::OnDetach()
	{
		SG_PROFILE_FUNCTION();

	}

	void Sandbox2D::OnUpdate(Timestep ts)
	{
		SG_PROFILE_FUNCTION();

		//Update
		m_CameraController.OnUpdate(ts);

		//Render
		Renderer2D::ResetStats();
		{
			SG_PROFILE_SCOPE("Renderer Prep");

			RenderCommand::SetClearColor({ 0.1F, 0.1F, 0.1F, 1 });
			RenderCommand::Clear();
		}

		{
			static float rotation = 0.f;
			rotation += ts * 50.f;

			SG_PROFILE_SCOPE("Renderer Draw");
			Renderer2D::BeginScene(m_CameraController.GetCamera());
			
			Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
			
			for (float y = -5.0f; y < 5.0f; y += 0.5f)
			{
				for (float x = -5.0f; x < 5.0f; x += 0.5f)
				{
					glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
					Renderer2D::DrawQuad({ x, y, 0.f }, { 0.45f, 0.45f }, color);
				}
			}
			Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.1f }, { 0.3f, 0.3f }, m_TextureStairs);
			Renderer2D::DrawRotatedQuad({ -0.6f, 0.0f , 0.1f}, { 0.3f, 0.6f }, glm::radians(rotation), m_TextureTree, 1.f, glm::vec4(0.5f));
			Renderer2D::DrawQuad({ -0.2f, 0.0f, 0.1f }, { 0.3f, 0.3f }, m_SquareColor);
			Renderer2D::DrawRotatedQuad({ 0.2f, 0.0f, 0.1f }, { 0.3f, 0.3f }, glm::radians(rotation), m_SquareColor);
			Renderer2D::DrawQuad({ 0.6f, 0.0f, 0.1f }, { 0.3f, 0.3f }, m_SquareColor);
			Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f, 0.1f }, { 0.3f, 0.3f }, glm::radians(rotation), m_SquareColor);

			Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.2f }, { 1.0f, 1.0f }, m_ChernoLogoTexture, 10.0f, glm::vec4(0.2f, 0.4f, 0.2f, 0.7f));

			Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, 0.3f }, { 1.0f, 1.0f }, glm::radians(rotation), m_ChernoLogoTexture, 1.0f, glm::vec4(1.f));

			Renderer2D::EndScene();
		}
	}

	void Sandbox2D::OnImGuiRender()
	{
		SG_PROFILE_FUNCTION();

		ImGui::Begin("Settings");

		auto stats = Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();
		
	}

	void Sandbox2D::OnEvent(Event& e)
	{
		m_CameraController.OnEvent(e);
	}

}