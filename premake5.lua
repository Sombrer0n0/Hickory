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

include "Hickory/vendor/GLFW"
include "Hickory/vendor/Glad"
include "Hickory/vendor/imgui"

project "Hickory"
	location "Hickory"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hckpch.h"
	pchsource "Hickory/src/hckpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
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
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"HCK_PLATFORM_WINDOWS",
			"HCK_BUILD_DLL",
			"_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR",
			"GLFW_INCLUDE_NONE"
		}
		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "HCK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HCK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HCK_DIST"
		buildoptions "/MD"
		optimize "On"

	filter {"system:windows","configurations:Release"}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Hickory/src" 
	}

	links
	{
		"Hickory"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"HCK_PLATFORM_WINDOWS",
			"_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "HCK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HCK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HCK_DIST"
		buildoptions "/MD"
		optimize "On"

	filter {"system:windows","configurations:Release"}




