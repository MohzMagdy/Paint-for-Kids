#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriaAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ChangeColorAction.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
=======
#include "Actions\ChangeFillingAction.h"
#include "Actions\ChangeBorderAction.h"
>>>>>>> Stashed changes
=======
#include "Actions\ChangeFillingAction.h"
#include "Actions\ChangeBorderAction.h"
>>>>>>> Stashed changes

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
		case SELECT:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
=======
=======
>>>>>>> Stashed changes
		case CHNG_FILL_CLR:
			pAct = new ChangeFillingAction(this);
			break;

		case CHNG_PEN_SIZE:
			pAct = new ChangeBorderAction(this);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
			break;

		case EXIT:
			///create ExitAction here

			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
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

CFigure* ApplicationManager::P_FigList() 
{ return FigList[0];  }


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
