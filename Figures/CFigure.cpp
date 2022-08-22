#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

int CFigure::SelectCounter = 0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

double CFigure::Cal_Length(Point p1, Point p2)
{
	return pow((pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)), 0.5);
}

int CFigure::GetSelectCounter()
{
	return SelectCounter;
}

void CFigure::UpdateSelectCounter()
{
	SelectCounter--;
}


