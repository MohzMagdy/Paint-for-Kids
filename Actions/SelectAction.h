#pragma once
#include "Action.h"

class SelectAction : public Action
{
	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

