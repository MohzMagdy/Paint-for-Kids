#include "CCircle.h"

CCircle::CCircle(Point center, Point edge, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	centerPoint = center;
	edgePoint = edge;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCirc(centerPoint, edgePoint, FigGfxInfo, Selected);
}

bool CCircle::WithinMe(Point v)
{
	radius = Cal_Length(centerPoint, edgePoint);
	if ((Cal_Length(centerPoint, v) <= radius) && IsSelected())
	{
		SetSelected(false);
		SelectCounter--;
		return true;
	}
	else if ((Cal_Length(centerPoint, v) <= radius) && !IsSelected())
	{
		SetSelected(true);
		SelectCounter++;
		return true;
	}                         // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		return false;
	}
}

double CCircle::GetArea()
{ return 3.14 * pow(radius, 2);  }

double CCircle::GetPerimeter()
{  return 3.14 * radius * 2; }

string CCircle::PrintInfo()
{
	return "Circle: center = (" + to_string(centerPoint.x) + ", " + to_string(centerPoint.y) + "), radius = " + to_string(radius) + ", Area = " + to_string(GetArea()) + ", Perimeter = " + to_string(GetPerimeter());
}