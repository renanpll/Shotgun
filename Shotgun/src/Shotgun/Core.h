#pragma once

#ifdef SG_PLATFORM_WINDOWS
	#if SG_DYNAMIC_LINK
		#ifdef SG_BUILD_DLL
			#define SHOTGUN_API __declspec(dllexport)
		#else
			#define SHOTGUN_API __declspec(dllimport)
		#endif // SG_BUILD_DLL
	#else
		#define SHOTGUN_API
	#endif //SG_DYNAMIC_LINK
#else
	#error Platform not supported!
#endif // SG_PLATFORM_WINDOW

#define SG_ENABLE_ASSERTS 0

#ifdef SG_DEBUG
	#define SG_ENABLE_ASSERTS 1
#endif

#if SG_ENABLE_ASSERTS
	#define SG_ASSERT(x, ...) { if(!(x)) { SG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SG_CORE_ASSERT(x, ...) { if(!(x)) { SG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SG_ASSERT(x, ...)
	#define SG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SG_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)