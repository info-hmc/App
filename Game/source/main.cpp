#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include <cstdio>
#include <iostream>

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

void FixedUpdate(float DeltaTime)
{
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
	// std cout delta time
	std::cout << "Delta Time: " << DeltaTime << std::endl;
}

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
	
	// add debug end of the window title if in debug mode
	InitWindow(800, 600, "Imgui App");

	// get current monitor resolution
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);
	screenHeight /= 1.5f;
	screenWidth /= 1.5f;

	std::cout << "Screen Width: " << screenWidth << std::endl;
	std::cout << "Screen Height: " << screenHeight << std::endl;

	// set window resolution
	SetWindowSize(screenWidth, screenHeight);

	// window icon
	Image icon = LoadImage("appicon.png");
	if (icon.data != NULL)
	SetWindowIcon(icon);
	UnloadImage(icon);  // Unload icon image (not needed any more)

	// set windows min size
	SetWindowMinSize(800, 600);

	//setup imgui
	rlImGuiSetup();
	ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

	// fixed update time
	const float FIXED_UPDATE_TIME = 1.0f / 60.0f;
	float accumulator = 0.0f;
	float deltaTime = 0.0f;
	float previousTime = GetTime();

	while (!WantsToQuit)
	{
		BeginDrawing();
		ClearBackground(GRAY);
		rlImGuiBegin();	

		DrawFPS(10, 10);
		BasicWindow.Show();

		rlImGuiEnd();
		EndDrawing();
		float currentTime = GetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;

		accumulator += deltaTime;

		while (accumulator >= FIXED_UPDATE_TIME)
		{
			FixedUpdate(deltaTime);
			accumulator -= FIXED_UPDATE_TIME;
		}
		if (WindowShouldClose())
		{

			WantsToQuit = true;
		}
	}
	
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}

