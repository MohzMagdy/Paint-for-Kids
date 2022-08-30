#include "CRectangle.h"

CRectangle::CRectangle()
{

}

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
		start.x = Corner1.x;
		start.y = Corner2.y;
		if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter -= 1;
			return true;
		}
		else if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter += 1;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x > Corner2.x) && (Corner1.y > Corner2.y))
	{
		start.x = Corner2.x;
		start.y = Corner2.y;
		if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter -= 1;
			return true;
		}
		else if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y < Corner1.y) && (v.y > Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter += 1;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x > Corner2.x) && (Corner1.y < Corner2.y))
	{
		start.x = Corner2.x;
		start.y = Corner1.y;
		if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter -= 1;
			return true;
		}
		else if ((v.x < Corner1.x) && (v.x > Corner2.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter += 1;
			return true;
		}
		else
			return false;
	}
	else if ((Corner1.x < Corner2.x) && (Corner1.y < Corner2.y))
	{
		start.x = Corner1.x;
		start.y = Corner1.y;
		if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && IsSelected())
		{
			SetSelected(false);
			SelectCounter -= 1;
			return true;
		}
		else if ((v.x < Corner2.x) && (v.x > Corner1.x) && (v.y > Corner1.y) && (v.y < Corner2.y) && !IsSelected())
		{
			SetSelected(true);
			SelectCounter += 1;
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

CFigure* CRectangle::CopyInfo(CFigure* p)
{
	CRectangle* c = new CRectangle(*(p->GetPoints()), *(p->GetPoints() + 1), p->Get_Gfx());
	return c;
}

Point CRectangle::LocateStart()
{
	start.x = Corner1.x;
	start.y = Corner1.y;
	return start;
}

void CRectangle::SetPoints(Point p1, Point p2, Point p3)
{
	Corner1 = p1;
	Corner2 = p2;
}

Point* CRectangle::GetPoints()
{
	Point points[] = { Corner1, Corner2 };
	return points;
}

void CRectangle::CalDiff(Point v1, Point ref, CFigure* pfig)
{
	Point p1, p2;
	p1.x = v1.x + (*(pfig->GetPoints())).x - ref.x;
	p1.y = v1.y + (*(pfig->GetPoints())).y - ref.y;
	p2.x = v1.x + (*(pfig->GetPoints() + 1)).x - ref.x;
	p2.y = v1.y + (*(pfig->GetPoints() + 1)).y - ref.y;
	pfig->SetPoints(p1, p2, p2);
}