#include "ChangeFillingAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillingAction::ChangeFillingAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeFillingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreateColorToolBar();
	pOut->PrintMessage("Choose new filling color");

	ActionType FillingType = pIn->GetUserAction();

	color newFilling;
	bool style = true;

	switch (FillingType)
	{
	case SET_CLR_RED:
		newFilling = RED;
		break;
	case SET_CLR_GREEN:
		newFilling = GREEN;
		break;
	case SET_CLR_BLUE:
		newFilling = BLUE;
		break;
	case SET_CLR_NONE:
		style = false;
		break;
	}

	if (pManager->FigList[0]->GetSelectCounter() != 0) //Items are selected
	{
		for (int i = 0; i < (pManager->get_FigCount()); i++)
		{
			if ((pManager->FigList[i])->IsSelected())
			{
				pManager->FigList[i]->ChngFillClr(newFilling, style);
				pManager->FigList[i]->SetSelected(false);
				pManager->FigList[i]->UpdateSelectCounter();
			}
		}
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else //Change for new objects
	{
		UI.Style = style;
		if (style)
			UI.FillColor = newFilling;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeFillingAction::Execute()
{
	ReadActionParameters();
}
