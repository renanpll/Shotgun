project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Shotgun/vendor/spdlog/include",
		"%{wks.location}/Shotgun/src",
		"%{wks.location}/Shotgun/vendor",
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