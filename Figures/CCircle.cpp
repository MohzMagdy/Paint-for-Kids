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
	double radius = pow((pow((edgePoint.x - centerPoint.x), 2) + pow((edgePoint.y - centerPoint.y), 2)), 0.5);
	if ((pow((pow((v.x - centerPoint.x), 2) + pow((v.y - centerPoint.y), 2)), 0.5) <= radius) && IsSelected())
	{
		SetSelected(false);
		return false;
	}
	else if ((pow((pow((v.x - centerPoint.x), 2) + pow((v.y - centerPoint.y), 2)), 0.5) <= radius) && !IsSelected())
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