workspace "Shotgun"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Shotgun/vendor/GLFW/include"
IncludeDir["Glad"] = "Shotgun/vendor/Glad/include"
IncludeDir["ImGui"] = "Shotgun/vendor/imgui"

include "Shotgun/vendor/GLFW"
include "Shotgun/vendor/Glad"
include "Shotgun/vendor/imgui"

project "Shotgun"
	location "Shotgun"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "sgpch.h"
	pchsource "Shotgun/src/sgpch.cpp"

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
			"SG_PLATFORM_WINDOWS",
			"SG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines {"SG_DEBUG", "SG_ENABLE_ASSERTS"}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SG_Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SG_Dist"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"Shotgun/vendor/spdlog/include",
		"Shotgun/src"
	}

	links
	{
		"Shotgun"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SG_Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SG_Dist"
		buildoptions "/MD"
		optimize "On"