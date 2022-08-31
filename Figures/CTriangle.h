#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Point1;
	Point Point2;
	Point Point3;
	Point start;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual bool Draw(Output* pOut) const;
	virtual bool WithinMe(Point p, Output* pOut);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();

	virtual string SaveInfo();
	virtual CFigure* CopyInfo(CFigure*);
	virtual Point LocateStart();
	virtual void CalDiff(Point, Point, CFigure*);
	virtual void SetPoints(Point, Point, Point);
	virtual Point* GetPoints();
};

#endif