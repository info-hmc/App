#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "UImanager.h"
#include "Globals.h"
#include "LoginUI.h"

UIManager lUIManager;

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
	InitWindow(800, 600, "CPC 4");
	SetWindowMinSize(800, 600);
	rlImGuiSetup();
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	//update time
	const float FIXED_UPDATE_TIME = 1.0f / 60.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();
	float currentTime = 0.f;
	LoginUI* l_loginUI = new LoginUI;
	lUIManager.SetCurrentUI(l_loginUI);

	while (!WindowShouldClose())
	{
		currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		lUIManager.UpdateCurrentUI(deltaTime);

		BeginDrawing();
		rlImGuiBegin();			

		ClearBackground(GRAY);
		lUIManager.RenderCurrentUI();
		
		rlImGuiEnd();
		EndDrawing();
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}