#ifndef ADD_Tria_ACTION_H
#define ADD_Tria_ACTION_H

#include "Action.h"

class AddTriaAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriaGfxInfo;
public:
	AddTriaAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif
