#pragma once

#include "Core.h"

#include "Shotgun/Events/ApplicationEvent.h"
#include "Shotgun/Events/Event.h"
#include "Shotgun/Core/LayerStack.h"
#include "Window.h"

#include "Shotgun/Core/Timestep.h"

#include "Shotgun/ImGui/ImGuiLayer.h"

namespace Shotgun
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		static Application* s_Instance;
		Scope<Window> m_Window;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;

		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		bool OnWindowClose(WindowCloseEvent);
		bool OnWindowResize(WindowResizeEvent& e);
	};

	Application* CreateApplication();
}
