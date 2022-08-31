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
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool WithinMe(Point p, Output* pOut);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();

	virtual string SaveInfo();
	virtual CFigure* CopyInfo(CFigure*);
};

#endif