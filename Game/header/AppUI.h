#pragma once
#include "Templates.h"


class AppUI : UITemplate
{
public:
	void Shutdown() override;
	void Setup() override;
	void Tick(float DeltaTime) override;
	void Show() override;
};