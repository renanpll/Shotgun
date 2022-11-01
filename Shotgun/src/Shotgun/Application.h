#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Shotgun/LayerStack.h"
#include "Window.h"

#include "Shotgun/Core/Timestep.h"

#include "ImGui/ImGuiLayer.h"

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
		Scope<Window> m_Window;

		bool m_Running = true;
		
		LayerStack m_LayerStack;

		ImGuiLayer* m_ImGuiLayer;

		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent);
	};

	Application* CreateApplication();
}
