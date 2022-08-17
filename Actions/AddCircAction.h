#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"

class AddCircAction: public Action
{
private:
	Point center, edge; //Rectangle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif
