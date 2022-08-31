#include "ExitAction.h"
#include <fstream>

using namespace std;

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Check if user wants to save before loading
	if (pManager->get_FigCount() != 0)
	{
		pOut->PrintMessage("Do you want to save the current objects before exiting? (y/n)");
		string choice = pIn->GetSrting(pOut);
		if (choice == "y" || choice == "Y")
			pManager->ExecuteAction(SAVE);
		pOut->ClearStatusBar();
	}
}

void ExitAction::Execute()
{
	ReadActionParameters();
}

void ExitAction::Undo()
{}

void ExitAction::Redo()
{}

