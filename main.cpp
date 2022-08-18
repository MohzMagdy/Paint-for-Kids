#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	UI.InterfaceMode = MODE_DRAW;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);
	

	
	return 0;
}

