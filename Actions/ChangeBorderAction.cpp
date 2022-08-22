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

	switch (BorderType)
	{
	case SET_PEN_3PT:
		UI.PenWidth = 3;
		break;
	case SET_PEN_5PT:
		UI.PenWidth = 5;
		break;
	case SET_PEN_7PT:
		UI.PenWidth = 7;
		break;
	case SET_PEN_10PT:
		UI.PenWidth = 10;
		break;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeBorderAction::Execute()
{
	ReadActionParameters();
}
