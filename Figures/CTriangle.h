#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Point1;
	Point Point2;
	Point Point3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool WithinMe(Point p);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();
};

#endif