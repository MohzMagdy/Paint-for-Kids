#include "CRectangle.h"
#include <cmath>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::WithinMe(Point v)
{
	double a = pow((pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2)), 0.5);
	double b = pow((pow((Corner1.x - v.x), 2) + pow((Corner1.y - v.y), 2)), 0.5);
	double c = pow((pow((Corner2.x - v.x), 2) + pow((Corner2.y - v.y), 2)), 0.5);
	double s = (a + b + c) / 2;
	double A_v = pow(s * (s - a) * (s - b) * (s - c), 0.5);

	if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && IsSelected)
	{
		SetSelected(false);
		return false;
	}
	else if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && !IsSelected)
	{
		SetSelected(true);
		return true;
	}                           // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		SetSelected(false);
		return false;
	}
		

}