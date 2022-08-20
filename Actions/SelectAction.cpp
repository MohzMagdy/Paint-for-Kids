#include "SelectAction.h"


SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select the wanted figure");

	pIn->GetPointClicked(v1.x, v1.y);

	for (int i = (pManager->get_FigCount() - 1); i > -1; i--)
	{
		if ((pManager->FigList[i])->WithinMe(v1))
		{
			pOut->PrintMessage(pManager->FigList[i]->PrintInfo());
			pManager->FigList[i]->Draw(pOut);
			break;
		}
	}
		
}

void SelectAction::Execute()
{
	ReadActionParameters();

}

