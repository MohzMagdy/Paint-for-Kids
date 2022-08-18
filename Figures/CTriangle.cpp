#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawTria(Point1, Point2, FigGfxInfo, Selected);
}