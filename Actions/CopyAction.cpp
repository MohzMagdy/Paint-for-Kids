#include "CopyAction.h"
#include"..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Input.h"
#include "..\Figures\CFigure.h"


CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Copy the wanted figure");


	for (int i = 0; i < (pManager->Selected[i]->GetSelectCounter()); i++)
	{
		CFigure* p = pManager->FigList[i]->CopyInfo(pManager->FigList[i]);
		pManager->Selected[i]->SetSelected(false);
		pManager->FigList[i]->Draw(pOut);
		pManager->NewCopy(p);
			for (int i = 0; i < pManager->get_FigCount(); i++) {
				if (pManager->Copied[i] != NULL) {
					pOut->PrintMessage("Copy Action : Figure has been copied");
				}
			}
	}
}

void CopyAction::Execute() {
	ReadActionParameters();
}
