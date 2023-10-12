#include "UIManager.h"

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
	CurrentUI = UI;
	UI->Setup();
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
