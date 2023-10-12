#include "AppUI.h"
#include "imgui.h"
#include "Globals.h"

void AppUI::Shutdown()
{
}

void AppUI::Setup()
{
}

void AppUI::Tick(float DeltaTime)
{
}

void AppUI::Show()
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
