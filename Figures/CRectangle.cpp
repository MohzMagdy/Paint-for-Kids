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

bool CRectangle::WithinMe(Point v, Output* pOut)
{

	double s = (Cal_Length(Corner1, Corner2) + Cal_Length(Corner1, v) + Cal_Length(Corner2, v)) / 2;
	double A_v = pow(s * (s - Cal_Length(Corner1, Corner2)) * (s - Cal_Length(Corner1, v)) * (s - Cal_Length(Corner2, v)), 0.5);

	if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && IsSelected())
	{
		SetSelected(false);
		SelectCounter--;
		return true;
	}
	else if ((A_v <= (0.5 * abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y))) && !IsSelected())
	{
		SetSelected(true);
		SelectCounter++;
		return true;
	}                           // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		return false;
	}
}

double CRectangle::GetArea()
{
	return abs((Corner1.x - Corner2.x) * (Corner1.y - Corner2.y));
}

double CRectangle::GetPerimeter()
{
	return 2 * (abs((Corner1.x - Corner2.x)) + abs((Corner1.y - Corner2.y)));
}

string CRectangle::PrintInfo()
{
	float w = abs(Corner1.x - Corner2.x);
	float l = abs(Corner1.y - Corner2.y);
	return "Rectangle: Width = " + to_string(w) + ", Length = " + to_string(l) + ", Area = " + to_string(float(GetArea())) + ", Perimeter = " + to_string(float(GetPerimeter()));
}