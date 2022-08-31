#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
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

	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	CLine* L = new CLine(P1, P2, LineGfxInfo);
	if (L->Draw(pOut))
	{
		pManager->AddFigure(L);
	}
	else
	{
		pOut->PrintMessage("You Cannot draw outside the drawing area. Please Select The shape again and choose proper points.");
		delete L;
	}
		
	

}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

}

void AddLineAction::Undo()
{
	Output* pOut = pManager->GetOutput();

	int last_i = pManager->get_FigCount() - 1;
	delete pManager->FigList[last_i];
	pManager->DelFigure();
	pOut->ClearDrawArea();
}

void AddLineAction::Redo()
{
	CLine* L = new CLine(P1, P2, LineGfxInfo);

	pManager->AddFigure(L);
}