#pragma once
#include "Shotgun.h"

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
		Shotgun::OrthographicCameraController m_CameraController;

		Ref<VertexArray> m_VertexArray;
		Ref<Shader> m_FlatColorShader;
		Ref<FrameBuffer> m_FrameBuffer;

		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_ChernoLogoTexture;
		Ref<Texture2D> m_SpriteSheet;
		Ref<SubTexture2D> m_TextureStairs;
		Ref<SubTexture2D> m_TextureTree;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 0.7f };

	};
}