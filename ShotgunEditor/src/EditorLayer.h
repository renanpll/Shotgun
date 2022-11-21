#pragma once
#include "Shotgun.h"
#include "Panels/SceneHierarchyPanel.h"

namespace Shotgun {

	class EditorLayer : public Shotgun::Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

	private:
		bool OnKeyPressed(KeyPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();

	private:
		// TODO: remove these
		Entity m_squareEntity;
		Entity m_MainCameraEntity;
		Entity m_SecondCamera;
		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_ChernoLogoTexture;
		Ref<Texture2D> m_SpriteSheet;
		Ref<SubTexture2D> m_TextureStairs;
		Ref<SubTexture2D> m_TextureTree;

		EditorCamera m_EditorCamera;

		Ref<FrameBuffer> m_FrameBuffer;
		Ref<Scene> m_ActiveScene;

		int m_GizmoType = -1;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize;
		glm::vec2 m_ViewportBounds[2];

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;

	};
}
