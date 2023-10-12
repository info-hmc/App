#pragma once
#include "UIBase.h"

class AppUI : UIBase
{
public:
	void Shutdown() override;
	void Setup() override;
	void Tick(float DeltaTime) override;
	void Show() override;
};