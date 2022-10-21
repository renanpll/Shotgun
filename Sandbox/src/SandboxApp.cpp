
#include "Shotgun.h"

class ExampleLayer : public Shotgun::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(Shotgun::Event& event) override
	{
		if (event.GetEventType() == Shotgun::EventType::KeyPressed) {
			Shotgun::KeyPressedEvent& e = (Shotgun::KeyPressedEvent&) event;

			SG_INFO((char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Shotgun::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Shotgun::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Shotgun::Application* Shotgun::CreateApplication()
{
	return new Sandbox();
}