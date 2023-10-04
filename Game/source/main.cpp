#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include <cstdio>

bool WantsToQuit = false;
bool IsPaused = false;

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
		ImGui::Begin("About");
		ImGui::Text("Hello World");
		ImGui::End();
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Quit"))
			{
				WantsToQuit = true;
			}
			ImGui::EndMenu();
		}
	}

	void Update() override
	{
	}
};
basicwindow BasicWindow;

void FixedUpdate()
{

}

void UpdateWindow()
{
	if (!IsWindowFocused())
	{
		IsPaused = true;
		SetTargetFPS(20);
	}
	else
	{
		SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
	}
	if (WindowShouldClose())
	{
		WantsToQuit = true;
	}
}

int main(int argc, char* argv[])
{
	int screenWidth = 1200;
	int screenHeight = 900;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
	
	// add debug end of the window title if in debug mode
	InitWindow(screenWidth, screenHeight, "Imgui App");

	Image icon = LoadImage("appicon.png");
	if (icon.data != NULL)
	SetWindowIcon(icon);

	UnloadImage(icon);  // Unload icon image (not needed any more)

	//setup imgui
	rlImGuiSetup();
	ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	// fixed update time
	const float FIXED_UPDATE_TIME = 1.0f / 120.0f;
	float accumulator = 0.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();

	while (!WantsToQuit)
	{
		BeginDrawing();
		ClearBackground(GRAY);
		rlImGuiBegin();	

		DrawFPS(10, 10);
		UpdateWindow();

		BasicWindow.Show();

		rlImGuiEnd();
		EndDrawing();
		float currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;

		accumulator += deltaTime;

		while (accumulator >= FIXED_UPDATE_TIME)
		{
			FixedUpdate();
			accumulator -= FIXED_UPDATE_TIME;
		}
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}

