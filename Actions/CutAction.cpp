#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
	pManager->ClearCopyList();

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cut the wanted figure");

	int s = 0;

	for (int i = 0; i < (pManager->get_FigCount()); i++)
	{
		if ((pManager->FigList[i])->IsSelected())
		{
			CFigure* p = pManager->Selected[s]->CopyInfo(pManager->Selected[s]);
			pManager->NewCopy(p);
			delete pManager->FigList[i];
			pManager->Selected[s] = NULL;
			s += 1;
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

void CutAction::Execute() {
	ReadActionParameters();
}