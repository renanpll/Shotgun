#pragma once

#include "Shotgun/Core/Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Shotgun {
	
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}