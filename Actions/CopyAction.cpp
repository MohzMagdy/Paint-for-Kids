#include "CopyAction.h"



CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	pManager->ClearCopyList();

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Copy the wanted figure");

	int s = (pManager->Selected[0]->GetSelectCounter());
	for (int i = 0; i < s; i++)
	{
		CFigure* p = pManager->Selected[i]->CopyInfo(pManager->Selected[i]);
		pManager->Selected[i]->SetSelected(false);
		pManager->Selected[i]->Draw(pOut);
		pManager->Selected[i]->UpdateSelectCounter();
		pManager->Selected[i] = NULL;
		pManager->NewCopy(p);
	}
}

void CopyAction::Execute() {
	ReadActionParameters();
}
