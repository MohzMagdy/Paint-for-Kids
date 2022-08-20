#include "SelectAction.h"
#include "ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select the wanted figure");
	pIn->GetPointClicked(P1.x, P1.y);
	
	for (int i = (FigCount - 1); i < -1; i--)
	{
		if (FigList[i]->WithinMe(P1))
		{
			FigList[i]->Draw(pOut);
			break;
		}
	}
		
	
	pOut->ClearStatusBar();
}

void Execute()
{
	ReadActionParameters();

}

