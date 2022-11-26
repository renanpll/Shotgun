#include <Shotgun.h>
#include <Shotgun/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Shotgun::Application
{
public:
	Sandbox()
	{
		//PushLayer(new Shotgun::ExampleLayer());
		PushLayer(new Shotgun::Sandbox2D());
	}

	~Sandbox()
	{
	}

};

Shotgun::Application* Shotgun::CreateApplication(ApplicationCommandLineArgs args)
{
	return new Sandbox();
}
