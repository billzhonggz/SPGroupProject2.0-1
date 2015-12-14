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
	scanf("%d",&loginChoice);
	if (loginChoice==1)
	{
		system("cls");
		//printf("Debug mode: Go to Customer.\n");
		GUI_CustomerMain();
		return 1;
	}
	if (loginChoice==2)
	{
		int pwdCheck=0;
		do
		{
			printf("Please input your password.\n");
			char pwdInput[20];
			scanf("%s",pwdInput);
			pwdCheck=CheckPassword(pwdInput);
		}
		while (pwdCheck==1);
		//printf("Debug mode: Go to Manager\n");
		GUI_ManagerMain();
		return 0;
	}
	else 
		return 3;
}

void GUI_CustomerMain()
{
	system("cls");
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
	GUI_CustomerNumber(customerItemChoice);
}
void GUI_CustomerNumber(int itemID)
{
	system("cls");
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("      ****CUSTOMER INTERFACE****       \n");
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
		case 1: GUI_CustomerMain();
			break;
		case 2: Login();
			break;
		default : printf("Invalid input!\n");
	}
}

void GUI_ManagerMain()
{
	system("cls");
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("        ****MANAGER INTERFACE****       \n");
	printf("\n");
	printf("Please select an administrative function.\n");
	printf("\n");
	printf("1. Change inventory\n2. Change unit price\n3. Add new item\n4. Change password\n5. Go back to main menu\n");
	printf("\n");
	printf("INPUT    ");
	int managerMainInput;
	scanf("%d",&managerMainInput);
	switch (managerMainInput)
	{
		case 1: GUI_ManagerInventory()/*printf("Debug mode: Go to submenu inventory.\n")*/;
			break;
		case 2: /*GUI_ManagerPrice()*/printf("Debug mode: Go to submenu price.\n");
			break;
		case 3: /*GUI_ManagerItem()*/printf("Debug mode: Go to submenu item.\n");
			break;
		case 4: /*GUI_ManagerPwd()*/printf("Debug mode: Go to submenu password.\n");
			break;
		case 5: Login();
			break;
		default: printf("Invalid input!\n");
	}
}

void GUI_ManagerInventory()
{
	system("cls");
	printf("  ************************************  \n");
	printf("  *                                  *  \n");
	printf("  *  WELCOME TO THE GIT DRINK STORE  *  \n");
	printf("  *                                  *  \n");
	printf("  ************************************  \n");
	printf("\n");
	printf("        ****MANAGER INTERFACE****       \n");
	printf("\n");
	printf("        ****INVENTORY CHANGE****        \n");
	printf("\n");
	//Print out current item list.
	struct items *changeInventory;
	changeInventory = LoadItemList();
	int id = 1;
	printf("ID  Item         Amount    Price  \n");
	printf("0   Go back\n");
	do
	{
		printf("%d   %s            %d       %l2f   \n", id, changeInventory->name, changeInventory->amount, changeInventory->price);
		changeInventory = changeInventory->next;
		id++;
	} while (changeInventory == NULL);
	printf("\n");
	//Get user input ID.
	printf("Type ID number to select...\n");
	printf("\n");
	printf("INPUT   \n");
	int changeID;
	scanf("%d", &changeID);
	//Search and print out requesting item.
	struct items *beforeChangeItem;
	beforeChangeItem=SearchItem(changeID);
	printf("Item you want to change is %s, current inventory is %d.\n", beforeChangeItem->name, beforeChangeItem->amount);
	printf("\n");
	//Change inventory by increase/decrease.
	printf("INPUT CHANGES: INCREASE(POSITIVE INTEGER) / DECREASE(NEGATIVE INTEGER)  ");
	int inventoryChange;
	scanf("%d", &inventoryChange);
	int changeReturn;
	changeReturn = ChangeAmount(beforeChangeItem, inventoryChange, changeID);
	if (changeReturn == -1)
		printf("Change inventory failed: ID matching failed.\n");
	if (changeReturn == -2)
		printf("Change inventory failed: No enough initial inventory.\n");
	if (changeReturn == 0)
		printf("Change inventory succeed.\n");
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(changeID);
	printf("Inventory of item %s has changed to %d.\n", afterChangeItem->name, afterChangeItem->amount);
	printf("\n");
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Change other item(s)' inventory\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	//Exit this function.
	int inventoryBack;
	scanf("%d", &inventoryBack);
	switch (inventoryBack)
	{
		case 1: GUI_ManagerInventory();
			break;
		case 2: GUI_CustomerMain();
			break;
		case 3: Login();
			break;
		default: printf("Invalid input!\n");
			break;
	}
}

int CheckPassword(char *password)
{
	int cmpReturn;
	char readPwd[20];
	InitializeChar("#password",readPwd);
	cmpReturn=strcmp(readPwd,password);
	if (cmpReturn)
		return 1;
	return 0;
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