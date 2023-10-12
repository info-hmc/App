#pragma once
#include "UIBase.h"

class LoginUI : public UIBase
{
public:
	void Shutdown() override;
	void Setup() override;
	void Tick(float DeltaTime) override;
	void Show() override;
private:
};