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

#ifdef MN_ENABLE_ASSERTS
	#define MN_ASSERT(x, ...) { if(!(x)) {MN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MN_CORE_ASSERT(x, ...) { if(!(x)) { MN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MN_ASSERT(x, ...)
	#define MN_CORE_ASSERT(x, ...)
#endif // MN_ENABLE_ASSERTS


#define BIT(x) (1 << x)