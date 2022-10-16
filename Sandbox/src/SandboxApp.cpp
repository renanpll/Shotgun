
#include "Shotgun.h"

class Sandbox : public Shotgun::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Shotgun::Application* Shotgun::CreateApplication()
{
	return new Sandbox();
}