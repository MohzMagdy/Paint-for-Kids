#include "CLine.h"

CTriangle::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}
