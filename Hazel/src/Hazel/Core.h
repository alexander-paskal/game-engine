#pragma once

#include "hzpch.h"

#ifdef HZ_PLATFORM_WINDOWS // iF this is erring out, make sure macro is defined in properties -> preprocessor definitions 
// for both Hazel and application
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)  // Make sure that HZ_BUILD_DLL is listed in the definitions for Hazel
	#else
		#define HAZEL_API __declspec(dllimport) // Make sure it is NOT in Sandbox
	#endif

#else
	#error Hazel only supports Windows!
#endif

#define BIT(x) (1 << x)  // Shifts 1 by x places