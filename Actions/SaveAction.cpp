#include "SaveAction.h"
#include <fstream>

using namespace std;

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user for file name
	pOut->PrintMessage("Enter file name to save: ");
	string fileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	ofstream SaveFile("Saved Files\\" + fileName + ".txt");

	//Draw, fill, and background colors
	SaveFile << CFigure::ColorToString(UI.DrawColor) << " ";
	SaveFile << CFigure::ColorToString(UI.FillColor) << " ";
	SaveFile << CFigure::ColorToString(UI.BkGrndColor) << endl;

	//Figure count
	int figCount = pManager->get_FigCount();
	SaveFile << figCount << endl;

	//Go through objects to get their data
	for (int i = 0; i < figCount; i++)
	{
		SaveFile << pManager->FigList[i]->SaveInfo() << endl;
	}

	SaveFile.close();
}

void SaveAction::Execute()
{
	ReadActionParameters();
}

