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
			selected = pManager->FigList[i];
			pManager->FigList[i]->Draw(pOut);
			if (pManager->FigList[i]->GetSelectCounter() > 1)
				pOut->PrintMessage("Number of Selected Figures is " + to_string(pManager->FigList[i]->GetSelectCounter()));
			else
				pOut->PrintMessage(pManager->FigList[i]->PrintInfo());
			break;
		}
	}

	//Create a list of the selected figures
	for (int i = 0, k = 0; i < pManager->get_FigCount() /*&& k < pManager->FigList[i]->GetSelectCounter()*/ ; i++)
	{
		if (pManager->FigList[i]->IsSelected())
		{
			pManager->Selected[k] = pManager->FigList[i];
			pManager->FigList[i]->SetSelectCounter(k + 1);
			++k;
		}
	}
		
}

void SelectAction::Execute()
{
	ReadActionParameters();

}

void SelectAction::Undo()
{
	if (selected != nullptr)
	{
		selected->SetSelected(false);
		CFigure::SelectCounter--;

		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawArea();
	}
}

void SelectAction::Redo()
{
	if (selected != nullptr)
	{
		selected->SetSelected(true);
		CFigure::SelectCounter++;

		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawArea();
	}
}

