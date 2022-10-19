
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
		SG_TRACE("ExampleLayer::Update");
	}

	void OnEvent(Shotgun::Event& event) override
	{
		SG_INFO("{0}", event);
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