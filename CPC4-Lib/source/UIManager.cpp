#include "UIManager.h"

UIManager::~UIManager()
{
}

UIManager::UIManager()
{
	CurrentUI->Shutdown();
	delete CurrentUI;
}

void UIManager::SetCurrentUI(UIBase* UI)
{
	CurrentUI = UI;
	UI->Setup();
}

void UIManager::RenderCurrentUI()
{
	CurrentUI->Show();
}

void UIManager::UpdateCurrentUI(float DeltaTime)
{
	CurrentUI->Tick(DeltaTime);
}
