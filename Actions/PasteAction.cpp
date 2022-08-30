#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click where you want to paste");

	pIn->GetPointClicked(v1.x, v1.y);

	Point Ref = pManager->Copied[0]->LocateStart();

	for (int i = 0; i < pManager->GetCopyCounter(); i++)
	{
		Ref = pManager->Copied[i]->Closer(Ref, pManager->Copied[i]->LocateStart());
	}

	for (int i = 0; i < pManager->GetCopyCounter(); i++)
	{
		pManager->Copied[i]->CalDiff(v1, Ref, pManager->Copied[i]);
		pManager->Copied[i]->Draw(pOut);
		pManager->AddFigure(pManager->Copied[i]);

	}
	

	
}

void PasteAction::Execute()
{
	ReadActionParameters();

}