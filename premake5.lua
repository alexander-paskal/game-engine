workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src"
		"Hazel/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"HZ_PLATFORM_WINDOWS",
		"HZ_BUILD_DLL",
			
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_dir .. "/Sandbox")
	}

	filter "configurations.Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations.Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations.Dist"
		defines "HZ_DIST"
		optimize "On"





project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

	links
	{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"HZ_PLATFORM_WINDOWS",			
	}
 
	filter "configurations.Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations.Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations.Dist"
		defines "HZ_DIST"
		optimize "On"
