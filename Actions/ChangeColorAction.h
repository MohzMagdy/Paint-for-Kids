#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{
private:

public:
    ChangeColorAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
};

