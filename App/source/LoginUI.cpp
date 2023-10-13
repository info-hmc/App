#include "LoginUI.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include "Globals.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "AppUI.h"

void LoginUI::Shutdown()
{
	CloseWindow();
}

void LoginUI::Setup()
{
	SetWindowTitle("Login");
	SetWindowMinSize(320, 240);
	// set window resolution
	SetWindowSize(320, 240);
}

void LoginUI::Tick(float DeltaTime)
{
}

void LoginUI::Show()
{
	char Username[256] = "";
	char Password[256] = "";
	
	if (GuiButton(Rectangle{ 10, 200, 300, 30 }, "Login"))
	{
		AppUI* appui = new AppUI;
		_Globals.lUIManager.SetCurrentUI(appui);
	}

	GuiDrawText("Login", Rectangle{ 10, 10, 300, 30 }, TEXT_ALIGN_CENTER, Color (255, 255, 255));
	GuiTextBox(Rectangle{ 10, 50, 300, 30 }, Username, sizeof(Username), true);
}
