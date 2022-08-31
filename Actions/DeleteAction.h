#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class DeleteAction : public Action
{
private:
	int SelectCounter = CFigure::SelectCounter;
	CFigure** delFigList = new CFigure * [SelectCounter];
	int delFigListCounter = 0;

public:

	DeleteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();

	~DeleteAction();
};
