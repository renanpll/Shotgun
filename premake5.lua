include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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
