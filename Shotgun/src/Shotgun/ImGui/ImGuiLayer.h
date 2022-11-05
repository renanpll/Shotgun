#pragma once

#include "Shotgun/Core/Layer.h"

#include "Shotgun/Events/MouseEvent.h"
#include "Shotgun/Events/KeyEvent.h"
#include "Shotgun/Events/ApplicationEvent.h"

namespace Shotgun {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.f;

	};
}