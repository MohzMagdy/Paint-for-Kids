#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class RedoAction : public Action
{
public:

	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

