#include "UIManager.h"
#include <thread>
#include <chrono>

UIManager::~UIManager()
{
	ShutdownCurrentUI();
}

UIManager::UIManager()
{
}

void UIManager::SetCurrentUI(UIBase* UI)
{
	if (CurrentUI)
	{
		ShutdownCurrentUI();
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

void UIManager::ShutdownCurrentUI()
{
	if (!CurrentUI)
		return;
	CurrentUI->Shutdown();
	delete CurrentUI;
}
