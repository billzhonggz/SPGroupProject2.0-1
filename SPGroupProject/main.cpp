//
//  main.c
//  SPGroupProject
//
#define _CRT_SECURE_NO_WARNINGS
//  Copyright (c) 2015 TheBestGroup. All rights reserved.
// 

#include "main.h"

int main(int argc, const char * argv[]) {
	// example of de. a variable of type int
	// notice that: suggest to add "#" before variable name
	int softwareStatus = InitializeInt("#softwareStatus");
	int debugMode      = InitializeInt("#debugMode");
	// test-------------------------------------------------------------
	printf("The value of softwareStatus is %d\n",softwareStatus);
    printf("The value of debugMode is %d\n",debugMode);


	// example of de. a variable of type char
	// notice that: suggest to add "#" before variable name
	// char string[20];
	// InitializeChar("#string",string);
	// test-------------------------------------------------------------
	// printf("The value of string is %s\n",string);


	// example of change a value
	// avoid to use this func. unless really in need 
	ChangeConfigInt("#softwareStatus",0);
	ChangeConfigChar("#string","helloWorld");

	// example of call a function

	if(FirstScreen()) ErrorInformation("FirstScreen");
	// test
	Login();
    return 0;
}
