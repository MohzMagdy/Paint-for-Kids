#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = pOut->getCrntStyle();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	//Create a Circle with the parameters read from the user
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);
	if (R->Draw(pOut))
	{
		pManager->AddFigure(R);
	}
	else
	{
		pOut->PrintMessage("You Cannot draw outside the drawing area. Please Select The shape again and choose proper points.");
		delete R;
	}

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
}

void AddRectAction::Undo()
{
	Output* pOut = pManager->GetOutput();

	int last_i = pManager->get_FigCount() - 1;
	delete pManager->FigList[last_i];
	pManager->DelFigure();
	pOut->ClearDrawArea();
}

void AddRectAction::Redo()
{
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);

	pManager->AddFigure(R);
}