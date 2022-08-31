#include "CCircle.h"

CCircle::CCircle()
{

}

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

bool CCircle::WithinMe(Point v, Output* pOut)
{
	radius = Cal_Length(centerPoint, edgePoint);
	if ((Cal_Length(centerPoint, v) <= radius) && IsSelected())
	{
		SetSelected(false);
		SelectCounter--;
		return true;
	}
	else if ((Cal_Length(centerPoint, v) <= radius) && !IsSelected())
	{
		SetSelected(true);
		SelectCounter++;
		return true;
	}                         // Here we should print the figure info as well *mendokusai -_-*
	else
	{
		return false;
	}
}

double CCircle::GetArea()
{ return 3.14 * pow(radius, 2);  }

double CCircle::GetPerimeter()
{  return 3.14 * radius * 2; }

string CCircle::PrintInfo()
{
	return "Circle: center = (" + to_string(centerPoint.x) + ", " + to_string(centerPoint.y) + "), radius = " + to_string(radius) + ", Area = " + to_string(GetArea()) + ", Perimeter = " + to_string(GetPerimeter());
}

CFigure* CCircle::CopyInfo(CFigure* p)
{
	CCircle* c = new CCircle(*(p->GetPoints()), *(p->GetPoints() + 1), p->Get_Gfx());
	return c;
}

Point CCircle::LocateStart()
{
	start = Closer(centerPoint, edgePoint);
	return start;
}

void CCircle::CalDiff(Point v1, Point ref, CFigure* pfig)
{
	Point p1, p2;
	p1.x = v1.x + (*(pfig->GetPoints())).x - ref.x;
	p1.y = v1.y + (*(pfig->GetPoints())).y - ref.y;
	p2.x = v1.x + (*(pfig->GetPoints() + 1)).x - ref.x;
	p2.y = v1.y + (*(pfig->GetPoints() + 1)).y - ref.y;
	pfig->SetPoints(p1, p2, { 0, 0 });
}

void CCircle::SetPoints(Point p1, Point p2, Point p3)
{
	centerPoint = p1;
	edgePoint = p2;
}

Point* CCircle::GetPoints()
{
	Point points[] = { centerPoint, edgePoint };
	return points;
}

string CCircle::SaveInfo()
{
	string name = "CIRC";
	//id
	string center = PointToString(centerPoint);
	string edge = PointToString(edgePoint);
	string draw = ColorToString(FigGfxInfo.DrawClr);
	string border = to_string(FigGfxInfo.BorderWdth);
	string fill;
	if (FigGfxInfo.isFilled)
		fill = ColorToString(FigGfxInfo.FillClr);
	else
		fill = "NONE";

	return name + " " + center + " " + edge + " " + draw + " " + fill + " " + border;
}