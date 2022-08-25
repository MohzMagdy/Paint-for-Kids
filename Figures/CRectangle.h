#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool WithinMe(Point, Output* pOut);
	virtual string PrintInfo();
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual CFigure* CopyInfo(CFigure*);
};



#endif