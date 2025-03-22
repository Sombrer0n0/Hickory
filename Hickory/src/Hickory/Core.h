#pragma once

#ifdef HCK_PLATFORM_WINDOWS
	#ifdef HCK_BUILD_DLL
		#define HCK_API __declspec(dllexport)
	#else
		#define HCK_API __declspec(dllimport)
	#endif
#else
	#error HICKORY ONLY SUPPORT WINDOWS NOW!
#endif

#ifdef HCK_ENABLE_ASSERTS
	#define HCK_ASSERT(x, ...) { if(!(x)) { HCK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HCK_CORE_ASSERT(x, ...) { if(!(x)) { HCK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HCK_ASSERT(x, ...)
	#define HCK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)