include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Shotgun"
	architecture "x86_64"
	startproject "ShotgunEditor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Shotgun/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Shotgun/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Shotgun/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Shotgun/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Shotgun/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Shotgun/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Shotgun/vendor/yaml-cpp/include"

group "Dependencies"
	include "vendor/premake"
	include "Shotgun/vendor/GLFW"
	include "Shotgun/vendor/Glad"
	include "Shotgun/vendor/imgui"
	include "Shotgun/vendor/yaml-cpp"
group ""

include "Shotgun"
include "ShotgunEditor"
include "Sandbox"
