#pragma once

#ifdef SG_PLATFORM_WINDOWS
	#ifdef SG_BUILD_DLL
		#define SHOTGUN_API __declspec(dllexport)
	#else
		#define SHOTGUN_API __declspec(dllimport)
	#endif // SG_BUILD_DLL
#else
	#error Platform not supported!
#endif // SG_PLATFORM_WINDOW
