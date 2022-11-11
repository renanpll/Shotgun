#pragma once

#ifdef SG_PLATFORM_WINDOWS

extern Shotgun::Application* Shotgun::CreateApplication();

int main(int argc, char** argv)
{
	Shotgun::Log::Init();

	SG_PROFILE_BEGIN_SESSION("Startup", "ShotgunProfile-Startup.json");
	auto app = Shotgun::CreateApplication();
	SG_PROFILE_END_SESSION();

	SG_PROFILE_BEGIN_SESSION("Runtime", "ShotgunProfile-Runtime.json");
	app->Run();
	SG_PROFILE_END_SESSION();

	SG_PROFILE_BEGIN_SESSION("Shutdown", "ShotgunProfile-Shutdown.json");
	delete app;
	SG_PROFILE_END_SESSION();
}

#endif // SG_PLATFORM_WINDOWS