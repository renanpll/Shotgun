#include "sgpch.h"
#include "Application.h"

#include "Shotgun/Core/Input.h"
#include "Shotgun/Renderer/Renderer.h"

#include <GLFW/glfw3.h>

namespace Shotgun
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name, ApplicationCommandLineArgs args)
		: m_CommandLineArgs(args)
	{
		SG_PROFILE_FUNCTION();

		SG_CORE_ASSERT(!s_Instance, "Application already exists.")
		s_Instance = this;

		m_Window = Scope<Window>(Window::Create());
		m_Window->SetEventCallback(SG_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		SG_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::OnEvent(Event& e)
	{
		SG_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(SG_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(SG_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;

			(*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		SG_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		SG_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{
		SG_PROFILE_FUNCTION();

		while (m_Running)
		{
			SG_PROFILE_SCOPE("Run Loop");
			float time = (float)glfwGetTime(); // Temporary - move to platform
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized) {
				{
					SG_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
			}

			m_ImGuiLayer->Begin();
			{
				SG_PROFILE_SCOPE("LayerStack OnImGuiRenderer");

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent)
	{
		m_Running = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		SG_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}
