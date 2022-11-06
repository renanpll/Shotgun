#pragma once

#include "Shotgun/Core/Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Shotgun {
	
	class Input
	{
	public:
		inline static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }
		inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual float GetMouseXImpl() = 0;

	private:
		static Scope<Input> s_Instance;
	};
}