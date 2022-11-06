#pragma once

namespace Shotgun
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define SG_MOUSE_BUTTON_0      ::Shotgun::Mouse::Button0
#define SG_MOUSE_BUTTON_1      ::Shotgun::Mouse::Button1
#define SG_MOUSE_BUTTON_2      ::Shotgun::Mouse::Button2
#define SG_MOUSE_BUTTON_3      ::Shotgun::Mouse::Button3
#define SG_MOUSE_BUTTON_4      ::Shotgun::Mouse::Button4
#define SG_MOUSE_BUTTON_5      ::Shotgun::Mouse::Button5
#define SG_MOUSE_BUTTON_6      ::Shotgun::Mouse::Button6
#define SG_MOUSE_BUTTON_7      ::Shotgun::Mouse::Button7
#define SG_MOUSE_BUTTON_LAST   ::Shotgun::Mouse::ButtonLast
#define SG_MOUSE_BUTTON_LEFT   ::Shotgun::Mouse::ButtonLeft
#define SG_MOUSE_BUTTON_RIGHT  ::Shotgun::Mouse::ButtonRight
#define SG_MOUSE_BUTTON_MIDDLE ::Shotgun::Mouse::ButtonMiddle