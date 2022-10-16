#pragma once

#ifdef SG_PLATFORM_WINDOWS

extern Shotgun::Application* Shotgun::CreateApplication();

int main(int argc, char** argv)
{
	Shotgun::Log::Init();
	SG_CORE_INFO("Log Initialized!");

	auto app = Shotgun::CreateApplication();
	app->Run();
	delete app;
}

#endif // SG_PLATFORM_WINDOWS