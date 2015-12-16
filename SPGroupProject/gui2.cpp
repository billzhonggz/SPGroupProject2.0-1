#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"main.h"
#include"md5.h"

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
	int i;
	for (;;)
	{
		for (;;)
		{
			printf("Please input your manage password which is between 6 to 16 characters.\n");
			for (i = 0; i < 20; i++)
			{
				pwd[i] = _getch();
				if (pwd[i] == '\r')
					break;
				printf("*");
			}
			pwd[i] = '\0';
			//scanf("%s", pwd);
			if (strlen(pwd)<6 || strlen(pwd)>16)
				printf("Input a password between 6 to 16 characters!\n\n");
			else break;
		}
		printf("\nPlease input your password again.\n");
		for (i = 0; i < 20; i++)
		{
			pwdVerify[i] = _getch();
			if (pwdVerify[i] == '\r')
				break;
			printf("*");
		}
		pwdVerify[i] = '\0';
		//scanf("%s", pwdVerify);
		if (strcmp(pwd, pwdVerify) != 0)
			printf("Inputs are not same!\n\n");
		else
			break;
	}
	printf("\nEncrypting your password...\n\n");
	char szDigest[16];
	MD5Digest(pwd, strlen(pwd), szDigest);
	printf("Storing your password...\n\n");
	//for (int i=0;i<16;i++) printf ("%02X",(unsigned char)szDigest[i]);
	if (SavePassword("#password", szDigest))
	{
		printf("Password store failed.\n");
		return 1; // error
	}
	else
	{
		printf("Password stored seccessfully.\n");
		return 0;
	}
}

int Login()
{
	do
	{
system("cls");
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("  ****Welcome back!****  \n");
	printf("\n");
	printf("\n");
	printf("Please select to login.\n");
	printf("\n");
	printf("\n");
	printf("1. Customer\n");
	printf("\n");
	printf("2. Manager\n");
	printf("\n");
	printf("Please input your choice.\n");
	int loginChoice;
	scanf("%d", &loginChoice);
	if (loginChoice == 1)
	{
		system("cls");
		//printf("Debug mode: Go to Customer.\n");
		GUI_CustomerMain();
		return 1;
	}
	if (loginChoice == 2)
	{
		int pwdCheck = 0;
		for (;;)
		{
			printf("Please input your password.\n");
			char pwdInput[20];
			scanf("%s", pwdInput);
			if (pwdCheck != CheckPassword(pwdInput))
				printf("Password is incorrect!\n\n");
			else
				break;
		}
		while (pwdCheck == 1);
		//printf("Debug mode: Go to Manager\n");
		GUI_ManagerMain();
		return 0;
	}
	else
		return 3;
	}
	
}

int GUI_CustomerMain()
