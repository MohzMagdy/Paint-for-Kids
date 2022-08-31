#include "CLine.h"

CLine::CLine()
{
	
}

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	length = Cal_Length(Point1, Point2);
}


bool CLine::Draw(Output* pOut) const
{
	
	if (Point1.y > UI.ToolBarHeight && Point1.y < UI.height - UI.StatusBarHeight && Point2.y > UI.ToolBarHeight && Point2.y < UI.height - UI.StatusBarHeight)
	{
		if (Point1.x > 0 && Point1.x < UI.width && Point2.x > 0 && Point2.x < UI.width)
		{
			pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
			return true;
		}

	}
	return false;
}

bool CLine::WithinMe(Point v, Output* pOut)
{
	int w = (pOut->getCrntPenWidth()) / 3;
	if (((Cal_Length(Point1, v) + Cal_Length(Point2, v) <= (length + w)) && (Cal_Length(Point1, v) + Cal_Length(Point2, v) >= (length - w))) && IsSelected())
	{
		SetSelected(false);
		SelectCounter--;
		return true;
	}
	else if (((Cal_Length(Point1, v) + Cal_Length(Point2, v) <= (length + w)) && (Cal_Length(Point1, v) + Cal_Length(Point2, v) >= (length - w))) && !IsSelected())
	{
		SetSelected(true);
		SelectCounter++;
		return true;
	}                           // Here we should print the figure info as well *mendokusai -_-*
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

string CLine::SaveInfo()
{
	string name = "LINE";
	//id
	string P1 = PointToString(Point1);
	string P2 = PointToString(Point2);
	string draw = ColorToString(FigGfxInfo.DrawClr);
	string border = to_string(FigGfxInfo.BorderWdth);

	return name + " " + P1 + " " + P2 + " " + draw + " " + border;
}

CFigure* CLine::CopyInfo(CFigure* p)
{
	CLine* c = new CLine(*(p->GetPoints()), *(p->GetPoints() + 1), p->Get_Gfx());
	return c;
}

Point CLine::LocateStart()
{
	return Closer(Point1, Point2);
}

Point* CLine::GetPoints()
{
	Point points[] = { Point1, Point2 };
	return points;
}

void CLine::SetPoints(Point p1, Point p2, Point p3)
{
	Point1 = p1;
	Point2 = p2;
}

void CLine::CalDiff(Point v1, Point ref, CFigure* pfig)
{
	Point p1, p2;
	p1.x = v1.x + (*(pfig->GetPoints())).x - ref.x;
	p1.y = v1.y + (*(pfig->GetPoints())).y - ref.y;
	p2.x = v1.x + (*(pfig->GetPoints() + 1)).x - ref.x;
	p2.y = v1.y + (*(pfig->GetPoints() + 1)).y - ref.y;
	pfig->SetPoints(p1, p2, { 0, 0 });
}