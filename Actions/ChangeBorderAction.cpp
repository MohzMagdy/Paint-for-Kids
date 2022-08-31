#include "ChangeBorderAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeBorderAction::ChangeBorderAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeBorderAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreatePenToolBar();
	pOut->PrintMessage("Choose new pen size");

	ActionType BorderType = pIn->GetUserAction();

	int newPenWidth;

	switch (BorderType)
	{
	case SET_PEN_3PT:
		newPenWidth = 3;
		break;
	case SET_PEN_5PT:
		newPenWidth = 5;
		break;
	case SET_PEN_7PT:
		newPenWidth = 7;
		break;
	case SET_PEN_10PT:
		newPenWidth = 10;
		break;
	}

	if (pManager->FigList[0]->GetSelectCounter() != 0) //Items are selected
	{

		for (int i = 0; i < (pManager->get_FigCount()); i++)
		{
			if ((pManager->FigList[i])->IsSelected())
			{
				pManager->FigList[i]->ChngBorderWidth(newPenWidth);
				pManager->FigList[i]->SetSelected(false);
				pManager->FigList[i]->ClearSelectCounter();
			}
		}

		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else //Change for new objects
	{
		UI.PenWidth= newPenWidth;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeBorderAction::Execute()
{
	ReadActionParameters();
}

void ChangeBorderAction::Undo()
{}

void ChangeBorderAction::Redo()
{}