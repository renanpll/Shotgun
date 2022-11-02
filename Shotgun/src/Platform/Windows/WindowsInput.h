#pragma once

#include "Shotgun/Core/Input.h"

namespace Shotgun {

	class WindowsInput : public Input
	{

	protected:
		virtual bool IsKeyPressedImpl(int keyCode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePosImpl() override;
		virtual float GetMouseYImpl() override;
		virtual float GetMouseXImpl() override;
	};
}