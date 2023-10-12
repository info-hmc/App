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

function check_raygui()
	if(os.isdir("lib/raygui") == false) then
		if(not os.isfile("raygui-master.zip")) then
			print("Raygui not found, downloading from github")
			local result_str, response_code = http.download("https://github.com/raysan5/raygui/archive/refs/heads/master.zip", "raygui-master.zip", {
				progress = download_progress,
				headers = { "From: Premake", "Referer: Premake" }
			})
		end
		print("Unzipping to " ..  os.getcwd())
		zip.extract("raygui-master.zip", os.getcwd())
		ensure_lib_directory()
		os.rename("raygui-master", "lib/raygui")
		os.remove("raygui-master.zip")
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

workspace "CPC4"
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
	check_raygui()

	include ("raylib_premake5.lua")
		
project "FloatingBoat"
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
		"lib/raygui",
		"FloatingBoat/header",
		"extras",
		"lib/rres/src"
	}

	vpaths 
	{
		["ImGui Files"] = { "lib/imgui/*.h","lib/imgui/*.cpp", "lib/imgui-master/*.h", "lib/imgui-master/*.cpp" },
		["FloatingBoat/Header Files"] = { "FloatingBoat/**.h", "FloatingBoat/header/**.hpp" },
    	["FloatingBoat/Source Files"] = { "FloatingBoat/**.cpp", "FloatingBoat/**.c" },
	}

	files 
	{
		"lib/imgui/*.h",
		"lib/imgui/*.cpp",
		"lib/raygui/src/**.h",
		"extras/**.h",
		"external/**.cpp",
		"external/**.h",
		"FloatingBoat/**.cpp",
		"FloatingBoat/**.h",
	}

	defines {"IMGUI_DISABLE_OBSOLETE_FUNCTIONS","IMGUI_DISABLE_OBSOLETE_KEYIO"}
-- End of engine

-- Basic Demo
	project "CPC 4 App"
	kind "ConsoleApp"
	language "C++"
	location "_build"
	targetdir "_bin/%{cfg.buildcfg}"
	
	vpaths 
	{
		["App/Header Files"] = { "App/header/**.h", "App/header/**.hpp" },
		["App/Source Files"] = { "App/**.cpp", "App/**.c" },
	}

	files 
	{
		"App/**.cpp",
		"App/**.c",
		"App/**.h",
	}

	includedirs
	{
		"App/header/",
		"external", 
		"lib/imgui",
		"lib/raygui/src",
		"FloatingBoat/header",
		"extras",
	}

	link_raylib()
	links {"FloatingBoat"}

	filter "action:vs*"
	debugdir "$(SolutionDir)"	

