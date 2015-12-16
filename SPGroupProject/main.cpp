//
//  main.c
//  SPGroupProject
//
#define _CRT_SECURE_NO_WARNINGS
//  Copyright (c) 2015 TheBestGroup. All rights reserved.
// 

#include "main.h"

int main(int argc, const char * argv[]) {
	struct items *itemList;
	itemList = LoadItemList();
	// example of de. a variable of type int
	// notice that: suggest to add "#" before variable name
	int softwareStatus = InitializeInt("#softwareStatus");
	int debugMode = InitializeInt("#debugMode");
	// test-------------------------------------------------------------
	//printf("The value of softwareStatus is %d\n", softwareStatus);
	//printf("The value of debugMode is %d\n", debugMode);
<<<<<<< HEAD

	if (debugMode) softwareStatus = 1;
=======
>>>>>>> refs/remotes/JiayuYANG/master

	if(debugMode) softwareStatus = 1;
	
	// example of de. a variable of type char
	// notice that: suggest to add "#" before variable name
	// char string[20];
	// InitializeChar("#string",string);
	// test-------------------------------------------------------------
	// printf("The value of string is %s\n",string);


	// example of change a value
<<<<<<< HEAD
	// avoid to use this func. unless really in need 
=======
	// avoid to use this func. unless really in need 
>>>>>>> refs/remotes/JiayuYANG/master
	//ChangeConfigInt("#softwareStatus",0);
	//ChangeConfigChar("#string","helloWorld");

	// start
<<<<<<< HEAD
	if (softwareStatus) // check if the first time running this program.
	{
		if (FirstScreen()) // check if error, if not, change softwareStatus
=======
	if(softwareStatus) // check if the first time running this program.
	{
		if(FirstScreen()) // check if error, if not, change softwareStatus
>>>>>>> refs/remotes/JiayuYANG/master
		{
			ErrorInformation("FirstScreen");
		}
		else
		{
<<<<<<< HEAD
			ChangeConfigInt("#softwareStatus", 0);
			Sleep(1500);
		}
	}

	if (Login(itemList)) ErrorInformation("Login");



	return 0;

=======
			ChangeConfigInt("#softwareStatus",0);
			Sleep(1500);
		}
	}
	
	if(Login(itemList)) ErrorInformation("Login");
	


    return 0;

>>>>>>> refs/remotes/JiayuYANG/master
}
