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
	void Authenticate();
	char Username[256] = "";
	char Password[256] = "";
};