#pragma once
#include "UIBase.h"

class UIManager
{
public:
	// Current UI deletion
	void ShutdownCurrentUI();

	// Getters and Setters 
	void SetCurrentUI(UIBase* UI);
	UIBase* GetCurrentUI() {return CurrentUI;};
	
	// Important to run these every update.
	void RenderCurrentUI();
	void UpdateCurrentUI(float DeltaTime);
	
	// UI Manager creation/deletion
	UIManager();
	~UIManager();

private:
	UIBase* CurrentUI;
};