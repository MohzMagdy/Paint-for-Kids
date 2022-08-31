#pragma once
#include "Action.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
#include"..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Input.h"

class CutAction :
    public Action
{
public:

	CutAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

