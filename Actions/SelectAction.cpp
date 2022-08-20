#include "SelectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select the wanted figure");

	pIn->GetPointClicked(v1.x, v1.y);

	for (int i = (pManager->get_FigCount() - 1); i < -1; i--)
	{
		if (pManager->P_FigList()->WithinMe(v1))
		{
			pManager->P_FigList()->Draw(pOut);
			break;
		}
	}
		
	
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	ReadActionParameters();

}

