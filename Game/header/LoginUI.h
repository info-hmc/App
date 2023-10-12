#pragma once
#include "Templates.h"

class LoginUI : UITemplate
{
public:
	void Shutdown() override;
	void Setup() override;
	void Tick(float DeltaTime) override;
	void Show() override;
};