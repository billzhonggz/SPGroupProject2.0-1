//
//  entrance.c
//  SPGroupProject
//
#define _CRT_SECURE_NO_WARNINGS
//  Copyright (c) 2015 TheBestGroup. All rights reserved.
// 

#include "main_gui3.h"

int Entrance(int softwareStatus) {
	struct items *itemList;
	itemList = LoadItemList();
	int loginReturn;
	int GUI_CustomerMainReturn;
	int GUI_CustomerNumberReturn;
	int GUI_ManagerMainReturn;
	int GUI_ManagerInventoryReturn;
	int GUI_ManagerPriceReturn;
	int GUI_ManagerItemReturn;
	int GUI_ManagerPwdReturn;
	// first start
	if (softwareStatus) // check if the first time running this program.
	{
		if (FirstScreen()) // check if error, if not, change softwareStatus
		{
			ErrorInformation("FirstScreen");
		}
		else
		{
			ChangeConfigInt("#softwareStatus", 0);
			Sleep(1500);
		}

	}
	// second start

	while (1)// Login interface (role choices meum)
	{
		if ((loginReturn = Login(itemList)) == -1)
		{
			printf("%d\n", loginReturn);
			ErrorInformation("Login");
		}
		else if (loginReturn == 1)
		{
			while (1)// GUI_CustomerMain interface
			{
				int breakToLogin = 0;
				if ((GUI_CustomerMainReturn = GUI_CustomerMain(itemList)) == 0)
				{
					break;
				}
				else
				{
					while (1)// GUI_CustomerNumber interface
					{
						if (GUI_CustomerNumberReturn = GUI_CustomerNumber(itemList, GUI_CustomerMainReturn) == 0)// Go to Login
						{
							breakToLogin = 1;
							break;
						}
						else // Go to GUI_CustomerMain
						{
							break;
						}

					}
					
				}
				if (breakToLogin) break;
			}
			
		}
		else if (loginReturn == 2)
		{

			while (1) // GUI_ManagerMain interface
			{
				int breakToLogin = 0;
				if ((GUI_ManagerMainReturn = GUI_ManagerMain()) == 0)
				{
					break;
				}
				else if(GUI_ManagerMainReturn == 1)
				{
					while (1) // GUI_ManagerInventory
					{
						if ((GUI_ManagerInventoryReturn = GUI_ManagerInventory(itemList)) == 0)// Go to Login()
						{
							breakToLogin = 1;
							break;
						}
						else if (GUI_ManagerInventoryReturn == 1) // Go to GUI_ManagerMain
						{
							break;
						}

					}

				}
				else if (GUI_ManagerMainReturn == 2)
				{
					while (1) // GUI_ManagerPrice
					{
						if ((GUI_ManagerPriceReturn = GUI_ManagerPrice(itemList)) == 0)
						{
							breakToLogin = 1;
							break;
						}
						else if (GUI_ManagerPriceReturn == 1) // Go to GUI_ManagerMain
						{
							break;
						}

					}

				}
				else if (GUI_ManagerMainReturn == 3)
				{
					while (1) // GUI_ManagerItem
					{
						if ((GUI_ManagerItemReturn = GUI_ManagerItem(itemList)) == 0)// Go to GUI_ManagerMain
						{
							break;
						}
						else if (GUI_ManagerItemReturn == 1) // Go to Login
						{
							breakToLogin = 1;
							break;
						}

					}

				}
				else if (GUI_ManagerMainReturn == 4)
				{
					while (1) // GUI_ManagerPwd
					{
						if ((GUI_ManagerPwdReturn = GUI_ManagerPwd(itemList)) == 0) // Go to Login
						{
							breakToLogin = 1;
							break;
						}
						else if (GUI_ManagerPwdReturn == 1) // Go to GUI_ManagerMain
						{
							break;
						}

					}

				}
				if (breakToLogin) break;
			}

		}

	}
	return 0;
}

