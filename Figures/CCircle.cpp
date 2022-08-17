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