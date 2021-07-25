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

#ifdef VCE_ENABLE_ASSERTS
#	define VCE_ASSERT(x, ...) {if(!(x)){ VCE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#	define VCE_CORE_ASSERT(x, ...) {if(!(x)){ VCE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#	define VCE_ASSERT(x, ...)
#	define VCE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define VCE_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)