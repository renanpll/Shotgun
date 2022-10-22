#pragma once

#include "Shotgun/Layer.h"

#include "Shotgun/Events/MouseEvent.h"
#include "Shotgun/Events/KeyEvent.h"
#include "Shotgun/Events/ApplicationEvent.h"

namespace Shotgun {

	class SHOTGUN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.f;

	};
}