#pragma once

#include "Shotgun/Core/Core.h"
#include "Shotgun/Core/Application.h"

#ifdef SG_PLATFORM_WINDOWS

extern Shotgun::Application* Shotgun::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Shotgun::Log::Init();

	SG_PROFILE_BEGIN_SESSION("Startup", "ShotgunProfile-Startup.json");
	auto app = Shotgun::CreateApplication({ argc, argv });
	SG_PROFILE_END_SESSION();

	SG_PROFILE_BEGIN_SESSION("Runtime", "ShotgunProfile-Runtime.json");
	app->Run();
	SG_PROFILE_END_SESSION();

	SG_PROFILE_BEGIN_SESSION("Shutdown", "ShotgunProfile-Shutdown.json");
	delete app;
	SG_PROFILE_END_SESSION();
}

#endif // SG_PLATFORM_WINDOWS
