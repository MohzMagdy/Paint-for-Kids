#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriaAction::AddTriaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at P1");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at P2");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at P3");

	pIn->GetPointClicked(P3.x, P3.y);

	TriaGfxInfo.isFilled = pOut->getCrntStyle();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriaGfxInfo.FillClr = pOut->getCrntFillColor();
	TriaGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriaGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
}

void AddTriaAction::Undo()
{
	Output* pOut = pManager->GetOutput();

	int last_i = pManager->get_FigCount() - 1;
	delete pManager->FigList[last_i];
	pManager->DelFigure();
	pOut->ClearDrawArea();
}

void AddTriaAction::Redo()
{
	CTriangle* T = new CTriangle(P1, P2, P3, TriaGfxInfo);

	pManager->AddFigure(T);
}