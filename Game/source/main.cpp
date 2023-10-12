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

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

	//update time
	const float FIXED_UPDATE_TIME = 1.0f / 60.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();
	float currentTime = 0.f;

	UIManager UIManager = new UIManager;
	UIManager.SetCurrentUI(LoginUI);

	while (!WantsToQuit)
	{
		currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		UIManager.UpdateCurrentUI();

		BeginDrawing();
		rlImGuiBegin();			

		ClearBackground(WHITE);
		UIManager.RenderCurrentUI();
		
		rlImGuiEnd();
		EndDrawing();

		if (WindowShouldClose())
		WantsToQuit = true;
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}