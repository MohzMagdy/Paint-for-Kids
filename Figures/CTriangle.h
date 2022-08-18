#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	CTriangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif