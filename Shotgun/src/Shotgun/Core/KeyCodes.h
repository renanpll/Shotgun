#pragma once

namespace Shotgun
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define SG_KEY_SPACE           ::Shotgun::Key::Space
#define SG_KEY_APOSTROPHE      ::Shotgun::Key::Apostrophe    /* ' */
#define SG_KEY_COMMA           ::Shotgun::Key::Comma         /* , */
#define SG_KEY_MINUS           ::Shotgun::Key::Minus         /* - */
#define SG_KEY_PERIOD          ::Shotgun::Key::Period        /* . */
#define SG_KEY_SLASH           ::Shotgun::Key::Slash         /* / */
#define SG_KEY_0               ::Shotgun::Key::D0
#define SG_KEY_1               ::Shotgun::Key::D1
#define SG_KEY_2               ::Shotgun::Key::D2
#define SG_KEY_3               ::Shotgun::Key::D3
#define SG_KEY_4               ::Shotgun::Key::D4
#define SG_KEY_5               ::Shotgun::Key::D5
#define SG_KEY_6               ::Shotgun::Key::D6
#define SG_KEY_7               ::Shotgun::Key::D7
#define SG_KEY_8               ::Shotgun::Key::D8
#define SG_KEY_9               ::Shotgun::Key::D9
#define SG_KEY_SEMICOLON       ::Shotgun::Key::Semicolon     /* ; */
#define SG_KEY_EQUAL           ::Shotgun::Key::Equal         /* = */
#define SG_KEY_A               ::Shotgun::Key::A
#define SG_KEY_B               ::Shotgun::Key::B
#define SG_KEY_C               ::Shotgun::Key::C
#define SG_KEY_D               ::Shotgun::Key::D
#define SG_KEY_E               ::Shotgun::Key::E
#define SG_KEY_F               ::Shotgun::Key::F
#define SG_KEY_G               ::Shotgun::Key::G
#define SG_KEY_H               ::Shotgun::Key::H
#define SG_KEY_I               ::Shotgun::Key::I
#define SG_KEY_J               ::Shotgun::Key::J
#define SG_KEY_K               ::Shotgun::Key::K
#define SG_KEY_L               ::Shotgun::Key::L
#define SG_KEY_M               ::Shotgun::Key::M
#define SG_KEY_N               ::Shotgun::Key::N
#define SG_KEY_O               ::Shotgun::Key::O
#define SG_KEY_P               ::Shotgun::Key::P
#define SG_KEY_Q               ::Shotgun::Key::Q
#define SG_KEY_R               ::Shotgun::Key::R
#define SG_KEY_S               ::Shotgun::Key::S
#define SG_KEY_T               ::Shotgun::Key::T
#define SG_KEY_U               ::Shotgun::Key::U
#define SG_KEY_V               ::Shotgun::Key::V
#define SG_KEY_W               ::Shotgun::Key::W
#define SG_KEY_X               ::Shotgun::Key::X
#define SG_KEY_Y               ::Shotgun::Key::Y
#define SG_KEY_Z               ::Shotgun::Key::Z
#define SG_KEY_LEFT_BRACKET    ::Shotgun::Key::LeftBracket   /* [ */
#define SG_KEY_BACKSLASH       ::Shotgun::Key::Backslash     /* \ */
#define SG_KEY_RIGHT_BRACKET   ::Shotgun::Key::RightBracket  /* ] */
#define SG_KEY_GRAVE_ACCENT    ::Shotgun::Key::GraveAccent   /* ` */
#define SG_KEY_WORLD_1         ::Shotgun::Key::World1        /* non-US #1 */
#define SG_KEY_WORLD_2         ::Shotgun::Key::World2        /* non-US #2 */

/* Function keys */
#define SG_KEY_ESCAPE          ::Shotgun::Key::Escape
#define SG_KEY_ENTER           ::Shotgun::Key::Enter
#define SG_KEY_TAB             ::Shotgun::Key::Tab
#define SG_KEY_BACKSPACE       ::Shotgun::Key::Backspace
#define SG_KEY_INSERT          ::Shotgun::Key::Insert
#define SG_KEY_DELETE          ::Shotgun::Key::Delete
#define SG_KEY_RIGHT           ::Shotgun::Key::Right
#define SG_KEY_LEFT            ::Shotgun::Key::Left
#define SG_KEY_DOWN            ::Shotgun::Key::Down
#define SG_KEY_UP              ::Shotgun::Key::Up
#define SG_KEY_PAGE_UP         ::Shotgun::Key::PageUp
#define SG_KEY_PAGE_DOWN       ::Shotgun::Key::PageDown
#define SG_KEY_HOME            ::Shotgun::Key::Home
#define SG_KEY_END             ::Shotgun::Key::End
#define SG_KEY_CAPS_LOCK       ::Shotgun::Key::CapsLock
#define SG_KEY_SCROLL_LOCK     ::Shotgun::Key::ScrollLock
#define SG_KEY_NUM_LOCK        ::Shotgun::Key::NumLock
#define SG_KEY_PRINT_SCREEN    ::Shotgun::Key::PrintScreen
#define SG_KEY_PAUSE           ::Shotgun::Key::Pause
#define SG_KEY_F1              ::Shotgun::Key::F1
#define SG_KEY_F2              ::Shotgun::Key::F2
#define SG_KEY_F3              ::Shotgun::Key::F3
#define SG_KEY_F4              ::Shotgun::Key::F4
#define SG_KEY_F5              ::Shotgun::Key::F5
#define SG_KEY_F6              ::Shotgun::Key::F6
#define SG_KEY_F7              ::Shotgun::Key::F7
#define SG_KEY_F8              ::Shotgun::Key::F8
#define SG_KEY_F9              ::Shotgun::Key::F9
#define SG_KEY_F10             ::Shotgun::Key::F10
#define SG_KEY_F11             ::Shotgun::Key::F11
#define SG_KEY_F12             ::Shotgun::Key::F12
#define SG_KEY_F13             ::Shotgun::Key::F13
#define SG_KEY_F14             ::Shotgun::Key::F14
#define SG_KEY_F15             ::Shotgun::Key::F15
#define SG_KEY_F16             ::Shotgun::Key::F16
#define SG_KEY_F17             ::Shotgun::Key::F17
#define SG_KEY_F18             ::Shotgun::Key::F18
#define SG_KEY_F19             ::Shotgun::Key::F19
#define SG_KEY_F20             ::Shotgun::Key::F20
#define SG_KEY_F21             ::Shotgun::Key::F21
#define SG_KEY_F22             ::Shotgun::Key::F22
#define SG_KEY_F23             ::Shotgun::Key::F23
#define SG_KEY_F24             ::Shotgun::Key::F24
#define SG_KEY_F25             ::Shotgun::Key::F25

/* Keypad */
#define SG_KEY_KP_0            ::Shotgun::Key::KP0
#define SG_KEY_KP_1            ::Shotgun::Key::KP1
#define SG_KEY_KP_2            ::Shotgun::Key::KP2
#define SG_KEY_KP_3            ::Shotgun::Key::KP3
#define SG_KEY_KP_4            ::Shotgun::Key::KP4
#define SG_KEY_KP_5            ::Shotgun::Key::KP5
#define SG_KEY_KP_6            ::Shotgun::Key::KP6
#define SG_KEY_KP_7            ::Shotgun::Key::KP7
#define SG_KEY_KP_8            ::Shotgun::Key::KP8
#define SG_KEY_KP_9            ::Shotgun::Key::KP9
#define SG_KEY_KP_DECIMAL      ::Shotgun::Key::KPDecimal
#define SG_KEY_KP_DIVIDE       ::Shotgun::Key::KPDivide
#define SG_KEY_KP_MULTIPLY     ::Shotgun::Key::KPMultiply
#define SG_KEY_KP_SUBTRACT     ::Shotgun::Key::KPSubtract
#define SG_KEY_KP_ADD          ::Shotgun::Key::KPAdd
#define SG_KEY_KP_ENTER        ::Shotgun::Key::KPEnter
#define SG_KEY_KP_EQUAL        ::Shotgun::Key::KPEqual

#define SG_KEY_LEFT_SHIFT      ::Shotgun::Key::LeftShift
#define SG_KEY_LEFT_CONTROL    ::Shotgun::Key::LeftControl
#define SG_KEY_LEFT_ALT        ::Shotgun::Key::LeftAlt
#define SG_KEY_LEFT_SUPER      ::Shotgun::Key::LeftSuper
#define SG_KEY_RIGHT_SHIFT     ::Shotgun::Key::RightShift
#define SG_KEY_RIGHT_CONTROL   ::Shotgun::Key::RightControl
#define SG_KEY_RIGHT_ALT       ::Shotgun::Key::RightAlt
#define SG_KEY_RIGHT_SUPER     ::Shotgun::Key::RightSuper
#define SG_KEY_MENU            ::Shotgun::Key::Menu