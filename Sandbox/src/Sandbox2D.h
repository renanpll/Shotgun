#pragma once
#include "Shotgun.h"

namespace Shotgun {

	class Sandbox2D : public Shotgun::Layer
	{
	public:
		Sandbox2D();
		virtual ~Sandbox2D() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

	private:
		Shotgun::OrthographicCameraController m_CameraController;

		// Temporary
		Shotgun::Ref<Shotgun::VertexArray> m_VertexArray;
		Shotgun::Ref<Shotgun::Shader> m_FlatColorShader;
		Shotgun::Ref<Shotgun::Texture2D> m_CheckerboardTexture;

		struct ProfileResult
		{
			const char* Name;
			float Time;
		};

		std::vector<ProfileResult> m_ProfileResults;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	};
}