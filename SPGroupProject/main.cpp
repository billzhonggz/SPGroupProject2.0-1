//
//  main.c
//  SPGroupProject
//
#define _CRT_SECURE_NO_WARNINGS
//  Copyright (c) 2015 TheBestGroup. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    
    //Read .dat file:
	int firstLogin = InitializeInt("#firstLogin");
	int debugMode      = InitializeInt("#debugMode");
    
    char string[20];
    InitializeChar("#string",string);

	printf("Debug:Done.");
    
    //Decide wether go into firstScreen().
    /*if(firstLogin)
    {
        if(FirstScreen()!=0)
        {
            ErrorInformation("Error in FirstScreen(firstLogin)/n");
            printf("The value of firstLogin is %d\n",firstLogin);
            return 0;
        }
        else
        {
            firstLogin = 0;//Run the firstScreen() successfully, never run it after this time.
        }
    }*/
    
    //Start Login & go into GUI:
    /*int loginStatus;
    switch(loginStatus = Login())
    {
        case 0:
			printf("Go into GUI_Manager.\n");
            //GUI_Manager();
            break;
        case 1:
			printf("Go into GUI_Customer.\n");
            //GUI_Customer();
            break;
        default:
            printf("Error in Login().\n");
            printf("Login() returns %d\n",loginStatus);
            return 0;
    }*/
	
    return 0;
}
