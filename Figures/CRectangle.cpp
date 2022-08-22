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
	if ((Corner1.x < Corner2.x) && (Corner1.y > Corner2.y))
	{
		if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter--;
			return true;
		}
		else if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter++;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x > Corner2.x) && (Corner1.y > Corner2.y))
	{
		if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter--;
			return true;
		}
		else if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter++;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x > Corner2.x) && (Corner1.y < Corner2.y))
	{
		if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter--;
			return true;
		}
		else if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter++;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x < Corner2.x) && (Corner1.y < Corner2.y))
	{
		if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter--;
			return true;
		}
		else if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter++;
			return true;
		}
		else
			return false;
	}         
}

double CRectangle::GetArea()
{
	return abs((Corner1.x - Corner2.x) * (Corner1.y - Corner2.y));
}

double CRectangle::GetPerimeter()
{
	return (2 * (abs((Corner1.x - Corner2.x)) + abs((Corner1.y - Corner2.y))));
}

string CRectangle::PrintInfo()
{
	float w = abs(Corner1.x - Corner2.x);
	float l = abs(Corner1.y - Corner2.y);
	return "Rectangle: Width = " + to_string(w) + ", Length = " + to_string(l) + ", Area = " + to_string(float(GetArea())) + ", Perimeter = " + to_string(float(GetPerimeter()));
}