#include "ChangeColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreateColorToolBar();
	pOut->PrintMessage("Choose new draw color");

	ActionType ColorType = pIn->GetUserAction();

	color newDrawColor;
	bool colorPicked = true;

	switch (ColorType)
	{
	case SET_CLR_RED:
		newDrawColor = RED;
		break;
	case SET_CLR_GREEN:
		newDrawColor = GREEN;
		break;
	case SET_CLR_BLUE:
		newDrawColor = BLUE;
		break;
	default:
		colorPicked = false;
		break;
	}

	if (pManager->FigList[0]->GetSelectCounter() != 0) //Items are selected
	{
		for (int i = 0; i < (pManager->get_FigCount()); i++)
		{
			if ((pManager->FigList[i])->IsSelected())
			{
				if(colorPicked)
					pManager->FigList[i]->ChngDrawClr(newDrawColor);
				pManager->FigList[i]->SetSelected(false);
				pManager->FigList[i]->ClearSelectCounter();
			}
		}

		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else //Change for new objects
	{
		if(colorPicked)
			UI.DrawColor = newDrawColor;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeColorAction::Execute()
{
	ReadActionParameters();
}
