#include "Shotgun.h"

#include "imgui/imgui.h"


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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

};

class Sandbox : public Shotgun::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Shotgun::Application* Shotgun::CreateApplication()
{
	return new Sandbox();
}