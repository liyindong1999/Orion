workspace "Orion"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Orion/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "Orion/ThirdParty/Glad/include"
IncludeDir["ImGui"] = "Orion/ThirdParty/imgui"
IncludeDir["glm"] = "Orion/ThirdParty/glm"

include "Orion/ThirdParty/GLFW"
include "Orion/ThirdParty/Glad"
include "Orion/ThirdParty/imgui"

project "Orion"
	location "Orion"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "OrionPCH.h"
	pchsource "Orion/src/OrionPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/ThirdParty/glm/glm/**.hpp",
		"%{prj.name}/ThirdParty/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/spdlog/include",
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
			"ORION_PLATFORM_WINDOWS",
			"ORION_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"ORION_DEBUG"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ORION_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ORION_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ORION_DIST"
		buildoptions "/MD"
		optimize "On"

project	"Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Orion/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Orion"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"ORION_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORION_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ORION_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ORION_DIST"
		buildoptions "/MD"
		optimize "On"