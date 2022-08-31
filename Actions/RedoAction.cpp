#include "RedoAction.h"

#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRectangle.h"
#include <fstream>

using namespace std;

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	ActionStack<ActionType>* pUndo = &pManager->undoStack;
	ActionStack<Action*>* pUndoParams = &pManager->undoStackParams;
	ActionStack<ActionType>* pRedo = &pManager->redoStack;
	ActionStack<Action*>* pRedoParams = &pManager->redoStackParams;

	//Pop action type and pointer from undo stack
	ActionType act = pRedo->pop();
	Action* pAct = pRedoParams->pop();

	//Push action type and pointer to redo stack
	pUndo->push(act);
	pUndoParams->push(pAct);

	pAct->Redo();
}

void RedoAction::Execute()
{
	ReadActionParameters();
}

void RedoAction::Undo()
{}

void RedoAction::Redo()
{}
