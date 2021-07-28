workspace "VisceralCombatEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include 3rd party libraries into the project
IncludeDir = {}
IncludeDir["GLFW"] = "%{prj.name}/vendor/GLFW/include"
IncludeDir["GLad"] = "%{prj.name}/vendor/GLad/include"
IncludeDir["ImGui"] = "%{prj.name}/vendor/ImGui"
IncludeDir["glm"] = "%{prj.name}/vendor/glm"

include "VisceralCombatEngine/vendor/GLFW"
include "VisceralCombatEngine/vendor/GLad"
include "VisceralCombatEngine/vendor/imgui"
--include "VisceralCombatEngine/vendor/glm"

project "VisceralCombatEngine"
	location "VisceralCombatEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "vcepch.h"
	pchsource "VisceralCombatEngine/src/vcepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"GLad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"VCE_PLATFORM_WINDOWS", 
			"VCE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines 
		{
			"VCE_DEBUG",
			"VCE_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VCE_DIST"
		runtime "Release"
		optimize "on"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"VisceralCombatEngine/vendor/spdlog/include",
		"VisceralCombatEngine/vendor/glm",
		"VisceralCombatEngine/src",
	}

	links
	{
		"VisceralCombatEngine"
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"VCE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines 
		{
			"VCE_DEBUG",
			"VCE_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VCE_DIST"
		runtime "Release"
		optimize "on"