workspace "Hazel"
	architecture "x64"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windodws"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			HZ_PLATFORM_WINDOWS,
			HZ_BUILD_DLL,
			
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
	location "Hazel"
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
		"%{prj.name}/vendor/spdlog/include",
		"Hazel/src"
	}

	links
	{
		"Hazel"
	}

	filter "system:windodws"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			HZ_PLATFORM_WINDOWS,			
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
