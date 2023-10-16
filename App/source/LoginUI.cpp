#include "LoginUI.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include "Globals.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "AppUI.h"
#include <iostream>

void LoginUI::Shutdown()
{
	CloseWindow();
}

ImGuiWindowFlags windowflags = 0;
void LoginUI::Setup()
{
	SetWindowTitle("Login");
	SetWindowMinSize(320, 240);
	// set window resolution
	SetWindowSize(320, 240);
	windowflags |= ImGuiWindowFlags_NoMove;
	windowflags |= ImGuiWindowFlags_NoScrollbar;
	windowflags |= ImGuiWindowFlags_NoTitleBar;
	windowflags |= ImGuiWindowFlags_NoCollapse;
	windowflags |= ImGuiWindowFlags_NoScrollWithMouse;
	windowflags |= ImGuiWindowFlags_NoResize;
	windowflags |= ImGuiWindowFlags_NoDecoration;
}

void LoginUI::Tick(float DeltaTime)
{
	if (WindowShouldClose())
	{
		_Globals.WantsToQuit = true;
	}
}

void LoginUI::Show()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(320, 240));
	if (ImGui::Begin("", nullptr, windowflags))
	{
		ImGui::Text("Login");
		ImGui::Spacing();
		ImGui::Text("Username");
		ImGui::SameLine();
		ImGui::InputText(" ", Username, IM_ARRAYSIZE(Username));
		ImGui::Text("Password");
		ImGui::SameLine();
		ImGui::InputText("##hiddenLabel", Password, IM_ARRAYSIZE(Password), ImGuiInputTextFlags_Password);
		if (ImGui::Button("login"))
		{
			Authenticate();
		}
	}
}

void LoginUI::Authenticate()
{
	// this is not a real autentication but just a example
	if (Password != "demo" && Username != "demo")
		return;

	AppUI* appui = new AppUI;
	_Globals.lUIManager.SetCurrentUI(appui);
	
}
