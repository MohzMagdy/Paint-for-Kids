#ifndef ADD_Tria_ACTION_H
#define ADD_Tria_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddTriaAction : public Action
{
private:
	Point P1, P2; //Triangle Corners
	GfxInfo TriaGfxInfo;
public:
	AddTriaAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
