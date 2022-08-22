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

	switch (FillingType)
	{
	case SET_CLR_RED:
		UI.Style = true;
		UI.FillColor = RED;
		break;
	case SET_CLR_GREEN:
		UI.Style = true;
		UI.FillColor = GREEN;
		break;
	case SET_CLR_BLUE:
		UI.Style = true;
		UI.FillColor = BLUE;
		break;
	case SET_CLR_NONE:
		UI.Style = false;
		break;
	}

	UI.InterfaceMode = UI.PrevInterfaceMode;
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}

void ChangeFillingAction::Execute()
{
	ReadActionParameters();
}
