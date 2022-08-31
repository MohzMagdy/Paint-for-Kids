#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class LoadAction : public Action
{
private:
	string* ToSegments(string, int);

protected:
	Point v1;

public:

	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

