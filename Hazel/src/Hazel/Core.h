#pragma once

#ifdef HZ_PLATFORM_WINDOWS // iF this is erring out, make sure macro is defined in properties -> preprocessor definitions
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif

#else
	#error Hazel only supports Windows!
#endif