#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include"main.h"

int FirstScreen()
{
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("   ****This is your FIRST running.****   \n");
	printf("\n");
	printf("****Please input your manage information.****\n");
	printf("\n");
	char pwd[20];
	char pwdVerify[20];
	do
	{
		printf("Please input your manage password which is between 6 to 20 characters.\n");
		gets_s(pwd);
		printf("Please input your password again.\n");
		gets_s(pwdVerify);
	}
	while (strcmp(pwdVerify,pwd));
	printf("Storing your password...\n");
	if (ChangeConfigChar("#password",pwd) == 0)
	{
		printf("Password stored seccessfully.\n");
		//system("cls");
		return 0;
	}
	else
	{
		printf("Password store failed.\n");
		return 1; // error
	}
}

