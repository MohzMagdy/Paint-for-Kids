#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(center.x, center.y);

	pOut->PrintMessage("New Circle: Click at edge");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(edge.x, edge.y);

	CircGfxInfo.isFilled = pOut->getCrntStyle();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(center, edge, CircGfxInfo);
	if (C->Draw(pOut))
	{
		pManager->AddFigure(C);
	}
	else
	{
		pOut->PrintMessage("You Cannot draw outside the drawing area. Please Select The shape again and choose proper points.");
		delete C;
	}
	
}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	
}
