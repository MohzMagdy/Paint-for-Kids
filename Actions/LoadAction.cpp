#include "LoadAction.h"
#include "SaveAction.h"
#include <iostream>
#include <fstream>

#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRectangle.h"

using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Check if user wants to save before loading
	if (pManager->get_FigCount() != 0)
	{
		pOut->PrintMessage("Do you want to save the current objects before loading? (y/n)");
		string choice = pIn->GetSrting(pOut);
		if (choice == "y" || choice == "Y")
			pManager->ExecuteAction(SAVE);
		pOut->ClearStatusBar();
	}

	//Ask user for file name
	pOut->PrintMessage("Enter file name to load: ");
	string fileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	ifstream LoadFile("Saved Files\\" + fileName + ".txt");
	string loadedText;

	//Clear all current objects
	for (int i = 0; i < (pManager->get_FigCount()); i++)
	{
			delete pManager->FigList[i];
			for (int j = 0, k = 1; j < (pManager->get_FigCount() - i) && k < (pManager->get_FigCount() - i + 1); j++, k++)
			{
				pManager->FigList[i + j] = pManager->FigList[i + k];
			}
			i = i - 1;
			delete pManager->FigList[pManager->get_FigCount() - 1];
			pManager->DelFigure();
	}

	//Loading Data
	//Draw, fill, and background colors
	LoadFile >> loadedText;
	UI.DrawColor = CFigure::StringToColor(loadedText);
	LoadFile >> loadedText;
	UI.FillColor = CFigure::StringToColor(loadedText);
	LoadFile >> loadedText;
	UI.BkGrndColor = CFigure::StringToColor(loadedText);

	getline(LoadFile, loadedText);
	getline(LoadFile, loadedText);

	//Shape objects
	while (getline(LoadFile, loadedText))
	{
		string type = loadedText.substr(0, 4);

		//Use data from string to generate new object
		if (type == "LINE")
		{
			//Extract data
			string* data = ToSegments(loadedText, 4);

			Point P1 = CFigure::StringToPoint(data[0]);
			Point P2 = CFigure::StringToPoint(data[1]);

			GfxInfo LineGfxInfo;
			LineGfxInfo.DrawClr = CFigure::StringToColor(data[2]);

			LineGfxInfo.BorderWdth = stoi(data[3]);
			CLine* L = new CLine(P1, P2, LineGfxInfo);
			pManager->AddFigure(L);

			delete[] data;
		}
		else if (type == "CIRC")
		{
			//Extract data
			string* data = ToSegments(loadedText, 5);
			
			Point center = CFigure::StringToPoint(data[0]);
			Point edge = CFigure::StringToPoint(data[1]);
			
			GfxInfo CircGfxInfo;
			CircGfxInfo.DrawClr = CFigure::StringToColor(data[2]);
			if (data[3] != "NONE")
			{
				CircGfxInfo.FillClr = CFigure::StringToColor(data[3]);
				CircGfxInfo.isFilled = true;
			}
			else
				CircGfxInfo.isFilled = false;

			//Construct new object
			CircGfxInfo.BorderWdth = stoi(data[4]);
			CCircle *C = new CCircle(center, edge, CircGfxInfo);
			pManager->AddFigure(C);

			delete[] data;
		}
		else if (type == "RECT")
		{
			//Extract data
			string* data = ToSegments(loadedText, 5);

			Point P1 = CFigure::StringToPoint(data[0]);
			Point P2 = CFigure::StringToPoint(data[1]);

			GfxInfo RectGfxInfo;
			RectGfxInfo.DrawClr = CFigure::StringToColor(data[2]);
			if (data[3] != "NONE")
			{
				RectGfxInfo.FillClr = CFigure::StringToColor(data[3]);
				RectGfxInfo.isFilled = true;
			}
			else
				RectGfxInfo.isFilled = false;


			RectGfxInfo.BorderWdth = stoi(data[4]);
			CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);
			pManager->AddFigure(R);

			delete[] data;
		}
		else if (type == "TRIA")
		{
			//Extract data
			string* data = ToSegments(loadedText, 6);

			Point P1 = CFigure::StringToPoint(data[0]);
			Point P2 = CFigure::StringToPoint(data[1]);
			Point P3 = CFigure::StringToPoint(data[2]);

			GfxInfo TriaGfxInfo;
			TriaGfxInfo.DrawClr = CFigure::StringToColor(data[3]);
			if (data[4] != "NONE")
			{
				TriaGfxInfo.FillClr = CFigure::StringToColor(data[4]);
				TriaGfxInfo.isFilled = true;
			}
			else
				TriaGfxInfo.isFilled = false;

			TriaGfxInfo.BorderWdth = stoi(data[5]);
			CTriangle* T = new CTriangle(P1, P2, P3, TriaGfxInfo);
			pManager->AddFigure(T);

			delete[] data;
		}
	}

	pOut->ClearDrawArea();
	CFigure::ClearSelectCounter();

	LoadFile.close();
		
}

void LoadAction::Execute()
{
	ReadActionParameters();
}

string* LoadAction::ToSegments(string st, int dataSize)
{
	string* data = new string[dataSize];
	int dataCounter = 0;
	string segment = "";
	for (int i = 5; i < size(st); i++)
	{
		if (st[i] == ' ')
		{
			data[dataCounter++] = segment;
			segment = "";
		}
		else
		{
			segment += st[i];
		}
	}
	data[dataCounter++] = segment;

	return data;
}

void LoadAction::Undo()
{}

void LoadAction::Redo()
{}
