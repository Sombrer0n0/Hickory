workspace "Hickory"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hickory/vendor/GLFW/include"
IncludeDir["Glad"] = "Hickory/vendor/Glad/include"
IncludeDir["ImGui"] = "Hickory/vendor/imgui"
IncludeDir["glm"] = "Hickory/vendor/glm"

group "Dependencies"
include "Hickory/vendor/GLFW"
include "Hickory/vendor/Glad"
include "Hickory/vendor/imgui"

group ""

project "Hickory"
	location "Hickory"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hckpch.h"
	pchsource "Hickory/src/hckpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
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
			"HCK_PLATFORM_WINDOWS",
			"HCK_BUILD_DLL",
			"_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR",
			"GLFW_INCLUDE_NONE"
		}
		
	buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "HCK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HCK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HCK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hickory/vendor/spdlog/include",
		"Hickory/src",
		"Hickory/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Hickory"
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"HCK_PLATFORM_WINDOWS",
			"_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "HCK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HCK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HCK_DIST"
		runtime "Release"
		optimize "on"




