#pragma once

class UIBase
{
public:
	virtual void Setup() = 0;
	virtual void Tick(float DeltaTime) = 0;
	virtual void Shutdown() = 0;
	virtual void Show() = 0;
};

class UIManager
{
public:
	void SetCurrentUI(UIBase* UI);
	UIBase* GetCurrentUI() {return CurrentUI;};
private:
	UIManager();
	~UIManager();
	UIBase* CurrentUI;
};