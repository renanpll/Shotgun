#include "sgpch.h"
#include "Shotgun/Core/Input.h"

#include "GLFW/glfw3.h"
#include "Shotgun/Core/Application.h"

namespace Shotgun {

	bool Input::IsKeyPressed(KeyCode key) {
		
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button) {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition() {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos, (float)yPos };
	}

	float Input::GetMouseY() {

		auto [x, y] = GetMousePosition();
		return y;
	}

	float Input::GetMouseX() {

		auto [x, y] = GetMousePosition();
		return x;
	}
}