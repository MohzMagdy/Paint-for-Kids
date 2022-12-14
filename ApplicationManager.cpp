#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriaAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ChangeColorAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\ChangeFillingAction.h"
#include "Actions\ChangeBorderAction.h"
#include "Actions\ChangeFillingAction.h"
#include "Actions\ChangeBorderAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\CopyAction.h"
#include "Actions\ExitAction.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"
#include "Actions/Pickbyfigure.h"
#include "Actions/Pickbycolor.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	CopyCounter = 0;

	//Create an array of figure pointers and set them to NULL
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		Copied[i] = NULL;
		Selected[i] = NULL;
	}
		
		
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case TO_PLAY:
			pOut->CreatePlayToolBar();
			pOut->PrintMessage("You are in Play mode!");
			break;

		case TO_DRAW:
			pOut->CreateDrawToolBar();
			pOut->PrintMessage("You are in Draw mode!");
			break;

		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_TRIA:
			pAct = new AddTriaAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChangeColorAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChangeFillingAction(this);
			break;

		case CHNG_PEN_SIZE:
			pAct = new ChangeBorderAction(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case UNDO:
			if(!undoStack.isEmpty())
				pAct = new UndoAction(this);
			break;

		case REDO:
			if (!redoStack.isEmpty())
				pAct = new RedoAction(this);
			break;

		case HIDE:
			pAct = new Pickbyfigure(this);
			break;

		case PICK_COLOR:
			pAct = new Pickbycolor(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		StackAction(ActType, pAct);
		pAct->Execute();//Execute
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
//Add a figure to the list of figures
void ApplicationManager::DelFigure()
{
	//delete pFig;
	FigCount--;
}
////////////////////////////////////////////////////////////////////////////////////

CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////

int ApplicationManager::get_FigCount() 
{ return FigCount; }

int ApplicationManager::getFigCount() const
{
	return FigCount;
}

CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(Point x, Output* y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->WithinMe(x, y))
			return FigList[i];
	}

	///Add your code here to search for a figure given a point x,y

	return NULL;
}


CFigure* ApplicationManager::P_FigList() 
{ return FigList[0];  }

////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::NewCopy(CFigure* fig)
{
	Copied[CopyCounter++] = fig;
}
/////////////////
int ApplicationManager::GetCopyCounter()
{
	return CopyCounter;
}

void ApplicationManager::ClearCopyList()
{
	for (int i = 0; i < CopyCounter; i++)
		Copied[i] = NULL;

	CopyCounter = 0;
}

//Adds actions to the undo/redo stack
void ApplicationManager::StackAction(ActionType act, Action* pAct)
{
	//Checks if the action is one of the ignored
	ActionType ignoredActions[8] = {EXIT, STATUS, SAVE, LOAD, TO_PLAY, TO_DRAW, UNDO, REDO};
	bool notIgnored = true;
	for (int i = 0; i < 8; i++)
	{
		if (act == ignoredActions[i])
		{
			notIgnored = false;
		}
	}

	//Pushes the action type and action object to undo stacks and clears redo stacks
	if (notIgnored)
	{
		undoStack.push(act);
		undoStackParams.push(pAct);
		redoStack.clear();
		while(!redoStackParams.isEmpty())
			delete redoStackParams.pop();
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
