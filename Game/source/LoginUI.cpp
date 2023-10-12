#include "LoginUI.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"

void LoginUI::Shutdown()
{
}

void LoginUI::Setup()
{
	InitWindow(800, 600, "Login");
	SetWindowMinSize(800, 600);

	// get current monitor resolution
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	// set window resolution
	SetWindowSize((screenWidth / 1.5f), (screenHeight / 1.5f));
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
		if (ImGui::Button("nextui"))
		{
			
		}
		ImGui::End();
	}

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			

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
