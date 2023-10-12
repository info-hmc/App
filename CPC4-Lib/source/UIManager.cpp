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
