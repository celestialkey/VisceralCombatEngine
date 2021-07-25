project "GLad"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/kgrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}
	filter "system:linux"
		pic "On"
		systemversion "latest"

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
