#pragma once
#include "UIBase.h"

class UIManager
{
public:
	void SetCurrentUI(UIBase* UI);
	UIBase* GetCurrentUI() {return CurrentUI;};
	void RenderCurrentUI();
	void UpdateCurrentUI(float DeltaTime);
	void ShutdownCurrentUI();
	UIManager();
	~UIManager();
private:
	UIBase* CurrentUI;
};