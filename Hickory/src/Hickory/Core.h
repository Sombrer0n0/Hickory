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