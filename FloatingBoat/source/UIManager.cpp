#include "UIManager.h"
#include <thread>
#include <chrono>

UIManager::~UIManager()
{
	CurrentUI->Shutdown();
	delete CurrentUI;
}

UIManager::UIManager()
{
}

void UIManager::SetCurrentUI(UIBase* UI)
{
	if (CurrentUI)
	{
		CurrentUI->Shutdown();
		delete CurrentUI;
	}
	UI->Setup();
	CurrentUI = UI;
}

void UIManager::RenderCurrentUI()
{
	if (CurrentUI == nullptr)
		return;
	CurrentUI->Show();
}

void UIManager::UpdateCurrentUI(float DeltaTime)
{
	if (CurrentUI == nullptr)
		return;
	CurrentUI->Tick(DeltaTime);
}
