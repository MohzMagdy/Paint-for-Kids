#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}

bool CLine::WithinMe(Point v)
{
	double a = pow((pow((v.x - Point1.x), 2) + pow((v.y - Point1.y), 2)), 0.5);
	double b = pow((pow((v.x - Point2.x), 2) + pow((Point2.y - v.y), 2)), 0.5);
	double length = pow((pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2)), 0.5);
	if ((a + b <= length) && IsSelected)
	{
		SetSelected(false);
		return false;
	}
	else if ((a + b <= length) && !IsSelected)
	{
		SetSelected(true);
		return true;
	}                         // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		SetSelected(false);
		return false;
	}

}