#pragma once

#ifdef VCE_PLATFORM_WINDOWS
#	ifdef VCE_BUILD_DLL
#		define VCE_API __declspec(dllexport)
#	else
#		define VCE_API __declspec(dllimport)
#	endif
#else
#	error VCE only supports Windows!
#endif

#define BIT(x) (1 << x)