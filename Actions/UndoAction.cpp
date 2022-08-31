#include "UndoAction.h"
#include <fstream>

using namespace std;

UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void UndoAction::ReadActionParameters()
{
	ActionStack<ActionType>* pUndo = &pManager->undoStack;
	ActionStack<Action*>* pUndoParams = &pManager->undoStackParams;
	ActionStack<ActionType>* pRedo = &pManager->redoStack;
	ActionStack<Action*>* pRedoParams = &pManager->redoStackParams;

	//Pop action type and pointer from undo stack
	ActionType act = pUndo->pop();
	Action* pAct = pUndoParams->pop();

	//Push action type and pointer to redo stack
	pRedo->push(act);
	pRedoParams->push(pAct);
	
	pAct->Undo();
}

void UndoAction::Execute()
{
	ReadActionParameters();
}

void UndoAction::Undo()
{}

void UndoAction::Redo()
{}

