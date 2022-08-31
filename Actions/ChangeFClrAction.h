#ifndef CHANGEFCLRACTION_H_INCLUDED
#define CHANGEFCLRACTION_H_INCLUDED

#include "Action.h"

class ChangeFClrAction : public Action
{
private:
	Point P1, P2; //Line endpoints
	GfxInfo LineGfxInfo;
public:
	ChangeFClrAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};



#endif // CHANGEFCLRACTION_H_INCLUDED
