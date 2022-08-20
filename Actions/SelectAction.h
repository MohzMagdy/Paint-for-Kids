#pragma once
#include "Action.h"

class SelectAction : public Action
{
private:
	Point v1;

public:

	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

