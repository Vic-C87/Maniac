#pragma once

#ifdef MN_PLATFORM_WINDOWS
	#ifdef MN_BUILD_DLL
		#define MANIAC_API __declspec(dllexport)
	#else
		#define MANIAC_API __declspec(dllimport)
	#endif // MN_BUILD_DLL
#else
#error Maniac only supports Windows

#endif // MN_PLATFORM_WINDOWS

#define BIT(x) (1 << x)