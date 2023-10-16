#pragma once

class UIBase
{
public:
	virtual void Setup() = 0;
	virtual void Tick(float DeltaTime) = 0;
	virtual void Shutdown() = 0;
	virtual void Show() = 0;
};
