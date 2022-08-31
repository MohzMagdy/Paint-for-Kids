#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <cmath>
#include <string>


//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static Point Extra;
	
	
	/// Add more parameters if needed.

public:
	static int SelectCounter;
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual bool Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr, bool style);	//changes the figure's filling color
	void CFigure::ChngBorderWidth(int width);

	GfxInfo Get_Gfx();

	virtual bool WithinMe(Point c1, Output* pOut) = 0;
	double Cal_Length(Point p1, Point P2);
	Point Closer(Point, Point);
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual string PrintInfo() = 0;   
	static int GetSelectCounter();
	static void UpdateSelectCounter();
	static void ClearSelectCounter();

	virtual string SaveInfo() = 0;
	static string PointToString(Point);
	static Point StringToPoint(string);
	static bool CompareColors(color, color);
	static string ColorToString(color);
	static color StringToColor(string);
	virtual CFigure* CopyInfo(CFigure*) = 0;
	virtual Point LocateStart() = 0;
	virtual void CalDiff(Point, Point, CFigure*) = 0;
	virtual Point* GetPoints() = 0;
	virtual void SetPoints(Point, Point, Point) = 0;


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif