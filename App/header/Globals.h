#pragma once
#include "UIManager.h"

class Globals
{
public:
	bool WantsToQuit = false;
	UIManager lUIManager;
};

extern Globals _Globals;

