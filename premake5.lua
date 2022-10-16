workspace "Shotgun"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Shotgun"
	location "Shotgun"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SG_PLATFORM_WINDOWS",
			"SG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SG_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SG_Dist"
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
		symbols "On"

	filter "configurations:Release"
		defines "SG_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SG_Dist"
		optimize "On"