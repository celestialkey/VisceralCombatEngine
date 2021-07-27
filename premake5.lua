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
	kind "SharedLib"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VCE_PLATFORM_WINDOWS", 
			"VCE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Playground")
		}

	filter "configurations:Debug"
		defines 
		{
			"VCE_DEBUG",
			"VCE_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VCE_DIST"
		buildoptions "/MD"
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
		"VisceralCombatEngine/vendor/glm",
		"VisceralCombatEngine/src",
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
		defines 
		{
			"VCE_DEBUG",
			"VCE_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VCE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VCE_DIST"
		buildoptions "/MD"
		optimize "On"