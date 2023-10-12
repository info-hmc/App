#include "LoginUI.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include "Globals.h"

void LoginUI::Shutdown()
{
}

void LoginUI::Setup()
{
	InitWindow(800, 600, "CPC 4");
	SetWindowMinSize(800, 600);

	// get current monitor resolution
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	// set window resolution
	SetWindowSize((screenWidth / 1.5f), (screenHeight / 1.5f));

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	//setup imgui
	rlImGuiSetup();
	ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
}

void LoginUI::Tick(float DeltaTime)
{
}

void LoginUI::Show()
{
	if(Open)
	{ 
		ImGui::Begin("About");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
				WantsToQuit = true;

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("Example Window", nullptr, Open);

			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}
