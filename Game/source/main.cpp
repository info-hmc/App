#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include <cstdio>
#include <iostream>
#include "UImanager.h"
#include "LoginUI.h"
#include "Globals.h"

class DocumentWindow
{
public:
	bool Open = false;
	virtual void Setup() = 0;
	virtual void Shutdown() = 0;
	virtual void Show() = 0;
	virtual void Update() = 0;

	bool Focused = false;

	Rectangle ContentRect = { 0 };
};

class basicwindow : public DocumentWindow
{
	public:
	void Setup() override
	{
		Open = true;
	}

	void Shutdown() override
	{
		Open = false;
	}

	void Show() override
	{
		if (Open)
		{ 
			ImGui::Begin("About");
			ImGui::Text("Hello World");
			ImGui::End();
		}
	}

	void Update() override {}
};
basicwindow BasicWindow;

void MenuBar()
{
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
			ImGui::MenuItem("Example Window", nullptr, &BasicWindow.Open);

			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void Tick(float DeltaTime)
{
	ClearBackground(WHITE);
	MenuBar();
	BasicWindow.Show();
}

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
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

	//update time
	const float FIXED_UPDATE_TIME = 1.0f / 60.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();
	float currentTime = 0.f;

	UIManager UIManager = new UIManager;
	UIManager::SetCurrentUI(LoginUI);

	while (!WantsToQuit)
	{
		currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;

		BeginDrawing();
		rlImGuiBegin();			

		Tick(deltaTime);
		
		rlImGuiEnd();
		EndDrawing();

		if (WindowShouldClose())
		WantsToQuit = true;
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}

