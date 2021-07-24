workspace "VisceralCombatEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "VisceralCombatEngine"
	location "VisceralCombatEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "vcepch.h"
	pchsource "VisceralCombatEngine/src/vcepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VCE_PLATFORM_WINDOWS", 
			"VCE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Playground")
		}

	filter "configurations:Debug"
		defines "VCE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VCE_DIST"
		optimize "On"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"

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
		"VisceralCombatEngine/src"
	}

	links
	{
		"VisceralCombatEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VCE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VCE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VCE_DIST"
		optimize "On"