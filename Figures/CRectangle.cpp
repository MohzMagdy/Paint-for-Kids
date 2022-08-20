#include "CRectangle.h"


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

	double s = (Cal_Length(Corner1, Corner2) + Cal_Length(Corner1, v) + Cal_Length(Corner2, v)) / 2;
	double A_v = pow(s * (s - Cal_Length(Corner1, Corner2)) * (s - Cal_Length(Corner1, v)) * (s - Cal_Length(Corner2, v)), 0.5);

	if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && IsSelected())
	{
		SetSelected(false);
		return true;
	}
	else if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && !IsSelected())
	{
		SetSelected(true);
		return true;
	}                           // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		return false;
	}
}

double CRectangle::GetArea()
{
	return (Corner1.x - Corner2.x) * (Corner1.y - Corner2.y);
}

double CRectangle::GetPerimeter()
{
	return 2 * ((Corner1.x - Corner2.x) + (Corner1.y - Corner2.y));
}

string CRectangle::PrintInfo()
{
	return "Rectangle: Width = " + to_string(Corner1.x - Corner2.x) + ", Length = " + to_string(Corner1.y - Corner2.y) + ", Area = " + to_string(GetArea()) + ", Perimeter = " + to_string(GetPerimeter());
}