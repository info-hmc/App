#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "UImanager.h"
#include "Globals.h"
#include "LoginUI.h"

int main(int argc, char* argv[])
{
	SetConfigFlags(0);
	InitWindow(800, 600, "UnInit Window");
	rlImGuiSetup();
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	LoginUI* l_loginUI = new LoginUI;
	_Globals.lUIManager.SetCurrentUI(l_loginUI);

	while (!_Globals.WantsToQuit)
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

	return 0;
}