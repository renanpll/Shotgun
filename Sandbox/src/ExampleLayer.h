#pragma once

#include "Shotgun.h"

namespace Shotgun {

	class ExampleLayer : public Layer
	{
	public:
		ExampleLayer();
		virtual ~ExampleLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

	private:
		Ref<Shader> m_Shader;
		Ref<VertexArray> m_VertexArray;

		Ref<Shader> m_FlatColorShader;
		Ref<VertexArray> m_SquareVA;
		Ref<Texture2D> m_Texture;
		Ref<Texture2D> m_LogoTexture, m_ChernoLogoTexture;

		ShaderLibrary m_ShaderLibrary;

		OrthographicCameraController m_CameraController;
		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	};
}