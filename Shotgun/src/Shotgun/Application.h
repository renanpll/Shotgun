#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Shotgun/LayerStack.h"
#include "Window.h"

#include "ImGui/ImGuiLayer.h"
#include "Shotgun/Renderer/Shader.h"
#include "Renderer/Buffer.h"

namespace Shotgun
{
	class SHOTGUN_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

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

		ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;

		unsigned int m_VertexArray;

		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		bool OnWindowClose(WindowCloseEvent);
	};

	Application* CreateApplication();
}
