#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include <cstdio>
#include <iostream>
#include "UImanager.h"
#include "LoginUI.h"

UIManager lUIManager;
LoginUI l_loginUI;

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

	//update time
	const float FIXED_UPDATE_TIME = 1.0f / 60.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();
	float currentTime = 0.f;
	//lUIManager.SetCurrentUI(l_loginUI);

	while (!WindowShouldClose())
	{
		currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		lUIManager.UpdateCurrentUI(deltaTime);

		BeginDrawing();
		rlImGuiBegin();			

		ClearBackground(WHITE);
		lUIManager.RenderCurrentUI();
		
		rlImGuiEnd();
		EndDrawing();
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}