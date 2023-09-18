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
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	
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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"MN_PLATFORM_WINDOWS",
			"MN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
		}


	filter "configurations:Debug"
		defines "MN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MN_DIST"
		runtime "Release"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.glm}"
	}

	links
	{
		"Maniac"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"MN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MN_DIST"
		runtime "Release"
		optimize "On"