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

		FrameBufferSpecification spec;
		spec.Width = 1280;
		spec.Height = 720;

		m_FrameBuffer = FrameBuffer::Create(spec);
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

			m_FrameBuffer->Bind();
			
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

			m_FrameBuffer->UnBind();
		}
	}

	void Sandbox2D::OnImGuiRender()
	{
		SG_PROFILE_FUNCTION();

		// Note: Switch this to true to enable dockspace
		static bool dockingEnabled = true;
		if (dockingEnabled)
		{
			static bool dockspaceOpen = true;
			static bool opt_fullscreen_persistant = true;
			bool opt_fullscreen = opt_fullscreen_persistant;
			static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

			// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
			// because it would be confusing to have two docking targets within each others.
			ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			if (opt_fullscreen)
			{
				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
				window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
				window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			}

			// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
			if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
				window_flags |= ImGuiWindowFlags_NoBackground;

			// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
			// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
			// all active windows docked into it will lose their parent and become undocked.
			// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
			// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
			ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
			ImGui::PopStyleVar();

			if (opt_fullscreen)
				ImGui::PopStyleVar(2);

			// DockSpace
			ImGuiIO& io = ImGui::GetIO();
			if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
				ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
			}

			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					// Disabling fullscreen would allow the window to be moved to the front of other windows, 
					// which we can't undo at the moment without finer window depth/z control.
					//ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

					if (ImGui::MenuItem("Exit")) Application::Get().Close();
					ImGui::EndMenu();
				}

				ImGui::EndMenuBar();
			}

			ImGui::Begin("Settings");

			auto stats = Renderer2D::GetStats();
			ImGui::Text("Renderer2D Stats:");
			ImGui::Text("Draw Calls: %d", stats.DrawCalls);
			ImGui::Text("Quads: %d", stats.QuadCount);
			ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
			ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

			ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

			uint32_t textureID = m_FrameBuffer->GetColorAttachmentRendererID();
			ImGui::Image((void*)textureID, ImVec2{ 1280.0f, 720.0f });
			ImGui::End();

			ImGui::End();
		}
		else
		{
			ImGui::Begin("Settings");

			auto stats = Renderer2D::GetStats();
			ImGui::Text("Renderer2D Stats:");
			ImGui::Text("Draw Calls: %d", stats.DrawCalls);
			ImGui::Text("Quads: %d", stats.QuadCount);
			ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
			ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

			ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

			uint32_t textureID = m_FrameBuffer->GetColorAttachmentRendererID();
			ImGui::Image((void*)textureID, ImVec2{ 320.0f, 180.0f });
			ImGui::End();
		}
	}

	void Sandbox2D::OnEvent(Event& e)
	{
		m_CameraController.OnEvent(e);
	}

}