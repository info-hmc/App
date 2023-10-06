newoption
{
	trigger = "graphics",
	value = "OPENGL_VERSION",
	description = "version of OpenGL to build raylib against",
	allowed = {
		{ "opengl11", "OpenGL 1.1"},
		{ "opengl21", "OpenGL 2.1"},
		{ "opengl33", "OpenGL 3.3"},
		{ "opengl43", "OpenGL 4.3"}
	},
	default = "opengl33"
}

function define_C()
	language "C"
end

function define_Cpp()
	language "C++"
end

function string.starts(String,Start)
	return string.sub(String,1,string.len(Start))==Start
end

function link_to(lib)
	links (lib)
	includedirs ("../"..lib.."/lib", "../"..lib.."/" )
end

function download_progress(total, current)
	local ratio = current / total;
	ratio = math.min(math.max(ratio, 0), 1);
	local percent = math.floor(ratio * 100);
	print("Download progress (" .. percent .. "%/100%)")
end

function ensure_lib_directory()
    if not os.isdir("lib") then
        os.mkdir("lib")
    end
end

function check_raylib()
	if(os.isdir("lib/raylib") == false) then
		if(not os.isfile("raylib-master.zip")) then
			print("Raylib not found, downloading from github")
			local result_str, response_code = http.download("https://github.com/raysan5/raylib/archive/refs/heads/master.zip", "raylib-master.zip", {
				progress = download_progress,
				headers = { "From: Premake", "Referer: Premake" }
			})
		end
		print("Unzipping to " ..  os.getcwd())
		zip.extract("raylib-master.zip", os.getcwd())
		ensure_lib_directory()
		os.rename("raylib-master", "lib/raylib")
		os.remove("raylib-master.zip")
	end
end

function check_rayres()
	if(os.isdir("lib/rres") == false) then
		if(not os.isfile("rres-master.zip")) then
			print("Rayres not found, downloading from github")
			local result_str, response_code = http.download("https://codeload.github.com/raysan5/rres/zip/refs/tags/1.2.0", "rres-master.zip", {
				progress = download_progress,
				headers = { "From: Premake", "Referer: Premake" }
			})
		end
		print("Unzipping to " ..  os.getcwd())
		zip.extract("rres-master.zip", os.getcwd())
		ensure_lib_directory()
		os.rename("rres-1.2.0", "lib/rres")
		os.remove("rres-master.zip")
	end
end

function check_imgui()
	if(os.isdir("lib/imgui") == false) then
		if(not os.isfile("imgui-master.zip")) then
			print("imgui not found, downloading from github")
			local result_str, response_code = http.download("https://github.com/ocornut/imgui/archive/refs/heads/master.zip", "imgui-master.zip", {
				progress = download_progress,
				headers = { "From: Premake", "Referer: Premake" }
			})
		end
		print("Unzipping to " ..  os.getcwd())
		zip.extract("imgui-master.zip", os.getcwd())
		ensure_lib_directory()
		os.rename("imgui-master", "lib/imgui")
		os.remove("imgui-master.zip")
	end
end

workspace "App"
	configurations { "Debug", "Release" }
	platforms { "x64"}
	defaultplatform "x64"
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"	
		
	filter { "platforms:x64" }
		architecture "x86_64"
		
	targetdir "bin/%{cfg.buildcfg}/"
	

	cdialect "C99"
	cppdialect "C++20"
	check_raylib()
	check_imgui()
	check_rayres()

	include ("raylib_premake5.lua")
		
project "UnknowledgedEngine"
	kind "StaticLib"
	location "_build"
	targetdir "_bin/%{cfg.buildcfg}"
	language "C++"
	
	include_raylib()
	includedirs
	{ 
		"lib/rlImGui",
		"./external", 
		"lib/imgui",
		"UnknowledgedEngine/header",
		"extras",
		"lib/rres/src"
	}

	vpaths 
	{
		["ImGui Files"] = { "lib/imgui/*.h","lib/imgui/*.cpp", "lib/imgui-master/*.h", "lib/imgui-master/*.cpp" },
		["UnknowledgedEngine/Header Files"] = { "UnknowledgedEngine/**.h", "UnknowledgedEngine/header/**.hpp" },
    	["UnknowledgedEngine/Source Files"] = { "UnknowledgedEngine/**.cpp", "UnknowledgedEngine/**.c" },
	}

	files 
	{
		"lib/imgui/*.h",
		"lib/imgui/*.cpp",
		"extras/**.h",
		"external/**.cpp",
		"external/**.h",
		"UnknowledgedEngine/**.cpp",
		"UnknowledgedEngine/**.h",
		"lib/rayres/**.h",
	}

	defines {"IMGUI_DISABLE_OBSOLETE_FUNCTIONS","IMGUI_DISABLE_OBSOLETE_KEYIO"}
-- End of engine

-- Basic Demo
	project "Unknowledged Engine Demo"
	kind "ConsoleApp"
	language "C++"
	location "_build"
	targetdir "_bin/%{cfg.buildcfg}"
	
	vpaths 
	{
		["Game/Header Files"] = { "Game/header/**.h", "Game/header/**.hpp" },
		["Game/Source Files"] = { "Game/**.cpp", "Game/**.c" },
	}

	files 
	{
		"Game/**.cpp",
		"Game/**.c",
		"Game/**.h",
	}

	includedirs
	{
		"Game/header/",
		"external", 
		"lib/imgui",
		"UnknowledgedEngine/header",
		"extras",
		"lib/rres/src"
	}

	link_raylib()
	links {"UnknowledgedEngine"}

	filter "action:vs*"
	debugdir "$(SolutionDir)"	

