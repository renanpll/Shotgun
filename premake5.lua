workspace "Shotgun"
	architecture "x86_64"
	startproject "ShotgunEditor"

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
IncludeDir["glm"] = "Shotgun/vendor/glm"
IncludeDir["stb_image"] = "Shotgun/vendor/stb_image"
IncludeDir["entt"] = "Shotgun/vendor/entt/include"

group "Dependencies"
	include "Shotgun/vendor/GLFW"
	include "Shotgun/vendor/Glad"
	include "Shotgun/vendor/imgui"
group ""

--------------------------------------------------------------------------------------------

project "Shotgun"
	location "Shotgun"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "sgpch.h"
	pchsource "Shotgun/src/sgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
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
			"SG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines {"SG_DEBUG"}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SG_Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SG_Dist"
		runtime "Release"
		optimize "on"

--------------------------------------------------------------------------------------------

project "ShotgunEditor"
	location "ShotgunEditor"
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
		"Shotgun/vendor/spdlog/include",
		"Shotgun/src",
		"Shotgun/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Shotgun"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SG_Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SG_Dist"
		runtime "Release"
		optimize "on"

--------------------------------------------------------------------------------------------

project "Sandbox"
	location "Sandbox"
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
		"Shotgun/vendor/spdlog/include",
		"Shotgun/src",
		"Shotgun/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Shotgun"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SG_Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SG_Dist"
		runtime "Release"
		optimize "on"