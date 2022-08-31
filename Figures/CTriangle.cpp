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

string CTriangle::SaveInfo()
{
	string name = "TRIA";
	//id
	string P1 = PointToString(Point1);
	string P2 = PointToString(Point2);
	string P3 = PointToString(Point3);
	string draw = ColorToString(FigGfxInfo.DrawClr);
	string border = to_string(FigGfxInfo.BorderWdth);
	string fill;
	if (FigGfxInfo.isFilled)
		fill = ColorToString(FigGfxInfo.FillClr);
	else
		fill = "NONE";

	return name + " " + P1 + " " + P2 + " " + P3 + " " + draw + " " + fill + " " + border;
}

CFigure* CTriangle::CopyInfo(CFigure* p)
{
	CTriangle* c = new CTriangle;
	c->FigGfxInfo = FigGfxInfo;
	return c;
}