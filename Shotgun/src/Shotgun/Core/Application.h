#pragma once

#include "Core.h"

#include "Shotgun/Events/ApplicationEvent.h"
#include "Shotgun/Events/Event.h"
#include "Shotgun/Core/LayerStack.h"
#include "Window.h"

#include "Shotgun/Core/Timestep.h"

#include "Shotgun/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Shotgun
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Close();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		void Run();

		bool OnWindowClose(WindowCloseEvent);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		static Application* s_Instance;
		Scope<Window> m_Window;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;

		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();
}
