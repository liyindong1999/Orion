workspace "Orion"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Orion"
	location "Orion"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "OrionPCH.h"
	pchsource "Orion/src/OrionPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORION_PLATFORM_WINDOWS",
			"ORION_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ORION_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ORION_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORION_DIST"
		optimize "On"

project	"Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Orion/ThirdParty/spdlog/include",
		"Orion/src"
	}

	links
	{
		"Orion"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORION_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORION_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ORION_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORION_DIST"
		optimize "On"