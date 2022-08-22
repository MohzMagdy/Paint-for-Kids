#include"DeleteAction.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	for (int i = 0; i < (pManager->get_FigCount()); i++)
	{
		if ((pManager->FigList[i])->IsSelected())
		{	
			delete pManager->FigList[i];
			pManager->FigList[i]->UpdateSelectCounter();
			for (int j = 0, k = 1; j < (pManager->get_FigCount() - i) && k < (pManager->get_FigCount() - i + 1); j++, k++)
			{
				pManager->FigList[i + j] = pManager->FigList[i + k];
			}
			i = i - 1;
			delete pManager->FigList[pManager->get_FigCount() - 1];
			pManager->DelFigure();
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
		}
	}
}

void DeleteAction::Execute()
{
	ReadActionParameters();
}