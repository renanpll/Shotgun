#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Shotgun/LayerStack.h"
#include "Window.h"

namespace Shotgun
{
	class SHOTGUN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
		
		LayerStack m_LayerStack;

		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent);
	};

	Application* CreateApplication();
}
