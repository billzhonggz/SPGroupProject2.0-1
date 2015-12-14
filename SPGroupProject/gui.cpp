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
int Login()
{
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
	scanf("%d",&loginChoice);
	if (loginChoice==1)
	{
		system("cls");
		//printf("Debug mode: Go to Customer.\n");
		GUI_Customer();
		return 1;
	}
	if (loginChoice==2)
	{
		int pwdCheck;
		do
		{
			printf("Please input your password.\n");
			char pwdInput[20];
			gets(pwdInput);
			pwdCheck=CheckPassword(pwdInput);
		}
		while (pwdCheck==1);
		system("cls");
		printf("Debug mode: Go to Manager\n");
		//GUI_Manager();
		return 0;
	}
	else 
		return 3;
}

int CheckPassword(char *password)
{
	int cmpReturn;
	char readPwd[20];
	InitializeChar("#password",readPwd);
	cmpReturn=strcmp(readPwd,password);
	if (cmpReturn)
		return 0;
	return 1;
}
void GUI_Customer()
{
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("  ****CUSTOMER INTERFACE****  \n");
	printf("\n");
	printf("Now loading drink item list...\n");
	printf("\n");
	//Load item list.
	struct items *customerItem;
	customerItem=LoadItemList();
	//Get first address.
	if (customerItem==NULL)
		printf("Load item list failed. Please try again.\n");
	printf("We offer these drinks! :)\n");
	printf("ID  Item         Amount    Price  \n");
	printf("0   Exit\n");
	int id=1;
	do
	{
		printf("%d  %s           %d        %l2f   \n",id,customerItem->name,customerItem->amount,customerItem->price);
		customerItem=customerItem->next;
		id++;
	}
	while (customerItem==NULL);
	//Get user input.
	printf("\n");
	printf("Please input your choice by typing the item number. Type 0 to go back.\n");
	printf("\n");
	printf("YOU CHOOSE:    ");
	int customerItemChoice;
	scanf("%d",&customerItemChoice);
	if (customerItemChoice==0)
		Login();
	BuyNumberConfirm(customerItemChoice);
	system("cls");
}
void BuyNumberConfirm(int itemID)
{
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("  ****CUSTOMER INTERFACE****  \n");
	printf("\n");
	struct items *customerSearchResult;
	customerSearchResult=SearchItem(itemID);
	if (customerSearchResult==NULL)
		printf("Invalid input!\n");
	printf("Your choice is %s. Avibile amount is %d. Unit price is %l2f.\n",customerSearchResult->name,customerSearchResult->amount,customerSearchResult->price);
	printf("\n");
	printf("How many %s you want to buy?\n",customerSearchResult->name);
	int customerBuyNumber;
	printf("NUMBER YOU WANT TO BUY IS     ");
	scanf("%d",&customerBuyNumber);
	printf("\n");
	double totalPrice;
	totalPrice=customerBuyNumber*customerSearchResult->price;
	printf("You will buy %d %s. You should pay %l2f in total.\n",customerSearchResult->price,customerSearchResult->name,totalPrice);
	printf("\n");
	double paid;
	printf("YOU PAY     ");
	scanf("%l2f",&paid);
	if (paid < totalPrice)
		printf("Please pay enough money!\n");
	printf("Change is %l2f, thank you!\n",paid-totalPrice);
	//Go back choose.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Buy some other drinks!\n2. Go back to main menu.\n");
	int customerReturn;
	scanf("%d",&customerReturn);
	switch (customerReturn)
	{
		case '1': GUI_Customer();
			break;
		case '2': Login();
			break;
		default : printf("Invalid input!\n");
	}
}
struct items *SearchItem(int id)
{
	struct items *current;
	struct items *head;
	head=LoadItemList();
	current=head;
	for (int i=0;i<=id && current==NULL;i++)
	{
		current=current->next;
	}
	return current;
}