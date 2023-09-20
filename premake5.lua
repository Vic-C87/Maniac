workspace "Maniac"
	architecture "x64"	
	startproject "Sandbox"
	
	configurations  
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

IncludeDir = {}
IncludeDir["GLFW"] = "Maniac/vendor/GLFW/include"
IncludeDir["Glad"] = "Maniac/vendor/Glad/include"
IncludeDir["ImGui"] = "Maniac/vendor/imgui"
IncludeDir["glm"] = "Maniac/vendor/glm"

include "Maniac/vendor/GLFW"
include "Maniac/vendor/Glad"
include "Maniac/vendor/imgui"


project "Maniac"
	location "Maniac"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mnpch.h"
	pchsource "Maniac/src/mnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MN_PLATFORM_WINDOWS",
			"MN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "MN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MN_DIST"
		runtime "Release"
		optimize "on"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Maniac/vendor/spdlog/include",
		"Maniac/src",
		"Maniac/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Maniac"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MN_DIST"
		runtime "Release"
		optimize "on"