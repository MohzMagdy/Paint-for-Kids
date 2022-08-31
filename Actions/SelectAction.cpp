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
		if ((pManager->FigList[i])->WithinMe(v1, pOut))
		{
			pManager->FigList[i]->Draw(pOut);
			if (pManager->FigList[i]->GetSelectCounter() > 1)
				pOut->PrintMessage("Number of Selected Figures is " + to_string(pManager->FigList[i]->GetSelectCounter()));
			else
				pOut->PrintMessage(pManager->FigList[i]->PrintInfo());
			break;
		}
	}

	for (int i = 0, k = 0; i < pManager->get_FigCount() && k < pManager->FigList[i]->GetSelectCounter(); i++)
	{
		if (pManager->FigList[i]->IsSelected())
		{
			pManager->Selected[k] = pManager->FigList[i];
			++k;
		}
	}
		
}

void SelectAction::Execute()
{
	ReadActionParameters();

}

