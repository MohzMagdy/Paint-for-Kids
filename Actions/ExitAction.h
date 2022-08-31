#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class ExitAction : public Action
{
protected:
	Point v1;

public:

	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

