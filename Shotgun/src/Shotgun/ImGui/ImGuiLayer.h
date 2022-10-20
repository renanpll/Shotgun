#pragma once

#include "Shotgun/Layer.h"

namespace Shotgun {

	class SHOTGUN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.f;

	};
}