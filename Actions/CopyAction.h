#pragma once
#include "Action.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
class CopyAction :
	public Action
{

public:
	
	CopyAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

