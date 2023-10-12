#pragma once
#include "UIManager.h"

class Globals
{
public:
	bool WantsToQuit = false;
	UIManager lUIManager;
	bool QuitLogin;
};

extern Globals _Globals;

