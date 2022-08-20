#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	length = Cal_Length(Point1, Point2);
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}

bool CLine::WithinMe(Point v)
{
	if ((Cal_Length(Point1, v)+ Cal_Length(Point2, v) <= length) && IsSelected())
	{
		SetSelected(false);
		return true;
	}
	else if ((Cal_Length(Point1, v) + Cal_Length(Point2, v) <= length) && !IsSelected())
	{
		SetSelected(true);
		return true;
	}                         // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		return false;
	}
}

double CLine::GetArea()
{
	return 0;
}

double CLine::GetPerimeter()
{
	return 0;
}

string CLine::PrintInfo()
{
	return "Line: length = " + to_string(length) + ", starts from(" + to_string(Point1.x) + ", " + to_string(Point1.y) + "), to(" + to_string(Point2.x) + ", " + to_string(Point2.y) + ")" ;
}