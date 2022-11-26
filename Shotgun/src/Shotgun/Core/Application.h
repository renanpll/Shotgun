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
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			SG_CORE_ASSERT(index < Count, "");
			return Args[index];
		}
	};

	class Application
	{
	public:
		Application(const std::string& name = "Shotgun App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

	private:
		void Run();

		bool OnWindowClose(WindowCloseEvent);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		static Application* s_Instance;
		Scope<Window> m_Window;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;

		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication(ApplicationCommandLineArgs args);
}
