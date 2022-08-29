#include "CTriangle.h"

CTriangle::CTriangle()
{
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTria(Point1, Point2, Point3, FigGfxInfo, Selected);
}

bool CTriangle::WithinMe(Point p, Output* pOut)
{
	double s1 = (Cal_Length(Point1, Point2) + Cal_Length(Point1, p) + Cal_Length(Point2, p)) / 2;
	double A1 = pow(s1 * (s1 - Cal_Length(Point1, Point2)) * (s1 - Cal_Length(Point1, p)) * (s1 - Cal_Length(Point2, p)), 0.5);
	double s2 = (Cal_Length(Point1, Point3) + Cal_Length(Point1, p) + Cal_Length(Point3, p)) / 2;
	double A2 = pow(s2 * (s2 - Cal_Length(Point1, Point3)) * (s2 - Cal_Length(Point1, p)) * (s2 - Cal_Length(Point3, p)), 0.5);
	double s3 = (Cal_Length(Point2, Point3) + Cal_Length(Point2, p) + Cal_Length(Point3, p)) / 2;
	double A3 = pow(s3 * (s3 - Cal_Length(Point2, Point3)) * (s3 - Cal_Length(Point2, p)) * (s3 - Cal_Length(Point3, p)), 0.5);

	if ((((A1 + A2 + A3) <= GetArea() + 5) && ((A1 + A2 + A3) >= GetArea() - 5)) && IsSelected())
	{
		SetSelected(false);
		SelectCounter--;
		return true;
	}
	else if ((((A1 + A2 + A3) <= GetArea() + 5) && ((A1 + A2 + A3) >= GetArea() - 5)) && !IsSelected())
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

double CTriangle::GetArea()
{
	double s = (Cal_Length(Point1, Point2) + Cal_Length(Point1, Point3) + Cal_Length(Point2, Point3)) / 2;
	return pow(s * (s - Cal_Length(Point1, Point2)) * (s - Cal_Length(Point1, Point3)) * (s - Cal_Length(Point2, Point3)), 0.5);
}

double CTriangle::GetPerimeter()
{
	return Cal_Length(Point1, Point2) + Cal_Length(Point1, Point3) + Cal_Length(Point2, Point3);
}

string CTriangle::PrintInfo()
{
	return "Triangle: area = " + to_string(GetArea()) + ", Perimeter = " + to_string(GetPerimeter());
}

CFigure* CTriangle::CopyInfo(CFigure* p)
{
	CTriangle* c = new CTriangle(*(p->GetPoints()), *(p->GetPoints() + 1), *(p->GetPoints() + 2),  p->Get_Gfx());
	return c;
}

Point CTriangle::LocateStart()
{
	return Closer(Closer(Point1, Point2), Point3);
}

void CTriangle::SetPoints(Point p1, Point p2, Point p3)
{
	Point1 = p1;
	Point3 = p2;
	Point3 = p3;

}

Point* CTriangle::GetPoints()
{
	Point points[] = { Point1, Point2, Point3};
	return points;
}

void CTriangle::CalDiff(Point v1, Point ref, CFigure* pfig)
{
	Point p1, p2, p3;
	p1.x = v1.x + (*(pfig->GetPoints())).x - ref.x;
	p1.y = v1.y + (*(pfig->GetPoints())).y - ref.y;
	p2.x = v1.x + (*(pfig->GetPoints() + 1)).x - ref.x;
	p2.y = v1.y + (*(pfig->GetPoints() + 1)).y - ref.y;
	p3.x = v1.x + (*(pfig->GetPoints() + 2)).x - ref.x;
	p3.y = v1.y + (*(pfig->GetPoints() + 2)).y - ref.y;
	pfig->SetPoints(p1, p2, p3);
}

