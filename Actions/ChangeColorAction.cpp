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

	switch (ColorType)
	{
	case SET_CLR_RED:
		UI.DrawColor = RED;
		break;
	case SET_CLR_GREEN:
		UI.DrawColor = GREEN;
		break;
	case SET_CLR_BLUE:
		UI.DrawColor = BLUE;
		break;
	default:
		break;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeColorAction::Execute()
{
	ReadActionParameters();
}
