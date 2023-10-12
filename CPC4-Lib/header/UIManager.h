#pragma once
#include "UIBase.h"

class UIManager
{
public:
	void SetCurrentUI(UIBase* UI);
	UIBase* GetCurrentUI() {return CurrentUI;};
	void RenderCurrentUI();
	void UpdateCurrentUI(float DeltaTime);
private:
	UIManager();
	~UIManager();
	UIBase* CurrentUI;
};