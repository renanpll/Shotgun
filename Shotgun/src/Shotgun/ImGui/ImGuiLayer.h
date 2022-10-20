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

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.f;

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizedEvent(WindowResizeEvent& event);
	};
}