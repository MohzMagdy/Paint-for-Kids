#include "CRectangle.h"

CRectangle::CRectangle()
{

}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
//0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight
bool CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	if ((Corner1.y > UI.ToolBarHeight) && (Corner1.y < UI.height - UI.StatusBarHeight) && (Corner2.y > UI.ToolBarHeight) && (Corner2.y < UI.height - UI.StatusBarHeight))
	{
		if ((Corner1.x > 0) && (Corner1.x < UI.width) && (Corner2.x > 0) && (Corner2.x < UI.width))
		{
			pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
			return true;
		}

	}
	return false;
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

string CRectangle::SaveInfo()
{
	string name = "RECT";
	//id
	string C1 = PointToString(Corner1);
	string C2 = PointToString(Corner2);
	string draw = ColorToString(FigGfxInfo.DrawClr);
	string border = to_string(FigGfxInfo.BorderWdth);
	string fill;
	if (FigGfxInfo.isFilled)
		fill = ColorToString(FigGfxInfo.FillClr);
	else
		fill = "NONE";

	return name + " " + C1 + " " + C2 + " " + draw + " " + fill + " " + border;
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