#include "CopyAction.h"



CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	//To ensure that the clipboard is empty
	pManager->ClearCopyList();

	Output* pOut = pManager->GetOutput();

	int s = (pManager->Selected[0]->GetSelectCounter());
	for (int i = 0; i < s; i++)
	{
		CFigure* p = pManager->Selected[i]->CopyInfo(pManager->Selected[i]); //create a pointer to the new copy 
		pManager->Selected[i]->SetSelected(false);							//undo the selection
		pManager->Selected[i]->Draw(pOut);									//redraw it, so it is not higlighted anymore
		pManager->Selected[i]->UpdateSelectCounter();						//minus 1 from the select counter
		pManager->Selected[i] = NULL;										//replace the pointer to the initial figure with a null one
		pManager->NewCopy(p);												//add the new pointer to the clipborad
	}

	pOut->PrintMessage("The Figures have been copied");
}

void CopyAction::Execute() {
	ReadActionParameters();
}

void CopyAction::Undo()
{}

void CopyAction::Redo()
{}