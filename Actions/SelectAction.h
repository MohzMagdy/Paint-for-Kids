#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class SelectAction : public Action
{
protected:
	Point v1;
	static int SelectCounter;

public:

	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

