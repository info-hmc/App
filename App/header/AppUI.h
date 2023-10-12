#pragma once
#include "UIBase.h"

class AppUI : public UIBase
{
public:
	void Shutdown() override;
	void Setup() override;
	void Tick(float DeltaTime) override;
	void Show() override;

private:
	bool Open;
};