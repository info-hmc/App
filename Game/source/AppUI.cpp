#include "AppUI.h"
#include "imgui.h"

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
				_Globals.WantsToQuit = true;

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("Example Window", nullptr, Open);

			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}
