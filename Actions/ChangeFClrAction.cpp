#include "ChangeFClirAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFClrAction::ChangeFClrAction(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at P1");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at P2");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	TriaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriaGfxInfo.FillClr = pOut->getCrntFillColor();
	TriaGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}


//Execute the action
void ChangeFClrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CLine* L = new CLine(P1, P2, LineGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(L);
}
