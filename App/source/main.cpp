#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "UImanager.h"
#include "Globals.h"
#include "LoginUI.h"

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow(800, 600, "UnInit Window");
	rlImGuiSetup();
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	LoginUI* l_loginUI = new LoginUI;
	_Globals.lUIManager.SetCurrentUI(l_loginUI);

	while (!_Globals.QuitLogin)
	{
		_Globals.lUIManager.UpdateCurrentUI(GetFrameTime());

		BeginDrawing();
		rlImGuiBegin();			

		ClearBackground(WHITE);
		_Globals.lUIManager.RenderCurrentUI();
		
		rlImGuiEnd();
		EndDrawing();
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}