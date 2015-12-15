//gui.cpp by Bill.
//Last modification on Dec. 15th, 2015
//MD5 algrithm from http://blog.csdn.net/qinggebuyao/article/details/7995398
//Functions waiting for implementation are listed below...
//	Password length limitation.(Finished)
//	Password input failure information.(Finished)
//	Password encryption.(Unfinished)

#define _CRT_SECURE_NO_WARNINGS
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
	for( ; ; )
	{
		printf("Please input your manage password which is between 6 to 20 characters.\n");
		scanf("%s",pwd);
		printf("Please input your password again.\n");
		scanf("%s",pwdVerify);
		if (strlen(pwd)<6 || strlen(pwd)>20)
			printf("Input a password between 6 to 20 characters!\n\n");
		else if (strcmp(pwd,pwdVerify)!=0)
			printf("Inputs are not same!\n\n");
		else
			break;
	}
	printf("Encrypting your password...\n\n");
	char szDigest[16];
	MD5Digest(pwd,strlen(pwd),szDigest);
	printf("Storing your password...\n\n");
	//for (int i=0;i<16;i++) printf ("%02X",(unsigned char)szDigest[i]);
	if (SavePassword("#password",szDigest))
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
		for ( ; ; )
		{
			printf("Please input your password.\n");
			char pwdInput[20];
			scanf("%s",pwdInput);
			if (pwdCheck!=CheckPassword(pwdInput))
				printf("Password is incorrect!\n\n");
			else 
				break;
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
		printf("%d  %s           %d        %2f   \n",id,customerItem->name,customerItem->amount,customerItem->price);
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
	printf("Your choice is %s. Avibile amount is %d. Unit price is %2f.\n",customerSearchResult->name,customerSearchResult->amount,customerSearchResult->price);
	printf("\n");
	printf("How many %s you want to buy?\n",customerSearchResult->name);
	int customerBuyNumber;
	printf("NUMBER YOU WANT TO BUY IS     ");
	scanf("%d",&customerBuyNumber);
	printf("\n");
	double totalPrice;
	totalPrice=customerBuyNumber*customerSearchResult->price;
	printf("You will buy %d %s. You should pay %2f in total.\n",customerSearchResult->price,customerSearchResult->name,totalPrice);
	printf("\n");
	double paid;
	printf("YOU PAY     ");
	scanf("%2f",&paid);
	if (paid < totalPrice)
		printf("Please pay enough money!\n");
	printf("Change is %2f, thank you!\n",paid-totalPrice);
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
	printf("1. Change inventory\n\n2. Change unit price\n\n3. Add & delete items\n\n4. Change password\n\n5. Go back to main menu\n");
	printf("\n");
	printf("INPUT    ");
	int managerMainInput;
	scanf("%d",&managerMainInput);
	switch (managerMainInput)
	{
		case 1: GUI_ManagerInventory()/*printf("Debug mode: Go to submenu inventory.\n")*/;
			break;
		case 2: GUI_ManagerPrice()/*printf("Debug mode: Go to submenu price.\n")*/;
			break;
		case 3: GUI_ManagerItem()/*printf("Debug mode: Go to submenu item.\n")*/;
			break;
		case 4: GUI_ManagerPwd()/*printf("Debug mode: Go to submenu password.\n")*/;
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
		printf("%d   %s            %d       %2f   \n", id, changeInventory->name, changeInventory->amount, changeInventory->price);
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
	if (changeID == 0)
		GUI_ManagerMain();
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

void GUI_ManagerPrice()
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
	printf("        ****UNIT PRICE CHANGE****       \n");
	printf("\n");
	//Print out current item list.
	struct items *changePrice;
	changePrice = LoadItemList();
	int id = 1;
	printf("ID  Item         Amount    Price  \n");
	printf("0   Go back\n");
	do
	{
		printf("%d   %s            %d       %2f   \n", id, changePrice->name, changePrice->amount, changePrice->price);
		changePrice = changePrice->next;
		id++;
	} while (changePrice == NULL);
	printf("\n");
	//Get user input ID.
	printf("Type ID number to select...\n");
	printf("\n");
	printf("INPUT   \n");
	int changeID;
	scanf("%d", &changeID);
	if (changeID == 0)
		GUI_ManagerMain();
	//Search and print out requesting item.
	struct items *beforeChangeItem;
	beforeChangeItem = SearchItem(changeID);
	printf("Item you want to change is %s, current price is %d.\n", beforeChangeItem->name, beforeChangeItem->price);
	printf("\n");
	//Change price.
	printf("INPUT NEW PRICE  ");
	double priceChange;
	scanf("%d", &priceChange);
	int changeReturn;
	changeReturn = ChangePrice(beforeChangeItem, priceChange, changeID);
	if (changeReturn == -1)
		printf("Change price failed: ID matching failed.\n");
	if (changeReturn == 0)
		printf("Change price succeed.\n");
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(changeID);
	printf("Inventory of item %s has changed to %d.\n", afterChangeItem->name, afterChangeItem->price);
	printf("\n");
	//Exit this function.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Change other item(s)' price\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	int priceBack;
	scanf("%d", &priceBack);
	switch (priceBack)
	{
	case 1: GUI_ManagerPrice();
		break;
	case 2: GUI_CustomerMain();
		break;
	case 3: Login();
		break;
	default: printf("Invalid input!\n");
		break;
	}
}

void GUI_ManagerItem()
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
	printf("         ****ITEM MANAGEMENT****        \n");
	printf("\n");
	printf("1. Add a new item\n2. Delete an existing item\n0. Go back\n");
	printf("\n");
	printf("INPUT  ");
	int itemManegeChoose;
	scanf("%d", &itemManegeChoose);
	if (itemManegeChoose == 0)
		GUI_ManagerMain();
	if (itemManegeChoose == 1)
	{
		//Get user input one by one.
		printf("Add a new item\n");
		struct items *newItem=0;
		printf("Input new item name.\n");
		scanf("%s", newItem->name);//Crash here.
		printf("Input new initial inventory.\n");
		scanf("%d", &newItem->amount);
		printf("Input new unit price.\n");
		scanf("%2f", &newItem->price);
		printf("The new item is %s, initial inventory is %d, unit price is %2f.\n", newItem->name, newItem->amount, newItem->price);
		//Store new item to the dat file.
		printf("Applying your modication...\n");
		int addReturn;
		addReturn = AddItem(newItem, newItem->name, newItem->amount, newItem->price);
		if (addReturn == -1)
			printf("Item added failed. An existing item has a same name.\n");
		if (addReturn == 0)
			printf("Item added succeed.\n");
	}
	if (itemManegeChoose == 2)
	{
		printf("Delete an item.\n");
		struct items *beforeDel;
		beforeDel = LoadItemList();
		int id = 1;
		printf("ID  Item         Amount    Price  \n");
		printf("0   Go back\n");
		do
		{
			printf("%d   %s            %d       %2f   \n", id, beforeDel->name, beforeDel->amount, beforeDel->price);
			beforeDel = beforeDel->next;
			id++;
		} while (beforeDel == NULL);
		printf("\n");
		printf("Input the ID of deleting item.\n");
		printf("\n");
		printf("INPUT ID  ");
		int delID;
		scanf("%d", &delID);
		if (delID == 0)
			GUI_ManagerMain();
		struct items *delConfirm;
		delConfirm = SearchItem(delID);
		printf("Item you want to delete is %s. Its inventory is %d. Its unit price is %f.\nARE YOU SURE TO DELETE IT?\n", delConfirm->name, delConfirm->amount, delConfirm->price);
		printf("\n");
		printf("1. Confirm\n2. Suspend\n");
		printf("\n");
		printf("INPUT  ");
		int delConfirmInput;
		scanf("%d", &delConfirmInput);
		if (delConfirmInput == 1)
			int delReturn = DeleteItem(beforeDel, delID);
		if (delConfirmInput == 2)
			GUI_ManagerItem();
	}
	//Exit this function.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Do item management\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	int itemBack;
	scanf("%d", &itemBack);
	switch (itemBack)
	{
	case 1: GUI_ManagerItem();
		break;
	case 2: GUI_CustomerMain();
		break;
	case 3: Login();
		break;
	default: printf("Invalid input!\n");
		break;
	}
}

void GUI_ManagerPwd()
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
	printf("Change your password.\n");
	printf("\n");
	char currentPwd[20];
	for ( ; ; )
	{
		printf("Input current password.\n");
		scanf("%s", currentPwd);
		printf("\nVerifying your password...\n");
		if (CheckPassword(currentPwd))
			printf("Password is incorrect!\n\n");
		else 
		{
			printf("Your input is correct. Now change your password.\n\n");
			break;
		}
	}
	char newPwd[20];
	char newPwdVerify[20];
	for ( ; ; )
	{
		printf("Input your new password.\n");
		scanf("%s", newPwd);
		printf("Input new password again.\n");
		scanf("%s", newPwdVerify);
		if (strlen(newPwd)<6 || strlen(newPwd)>20)
			printf("Input a password between 6 to 20 characters!\n\n");
		else if (strcmp(newPwd,newPwdVerify)!=0)
			printf("Inputs are not same!\n\n");
		else
			break;
	}
	printf("Storing your new password...\n\n");
	char szDigest[16];
	MD5Digest(newPwd,strlen(newPwd),szDigest);
	int newPwdStore;
	newPwdStore=SavePassword("#password", szDigest);
	if (newPwdStore)
		printf("Stored failed.\n\n");
	else
		printf("Stored successfully!\n\n");
	//Exit this function.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Go back to manager menu\n2. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	int pwdBack;
	scanf("%d", &pwdBack);
	switch (pwdBack)
	{
	case 1: GUI_ManagerMain();
		break;
	case 2: Login();
		break;
	default: printf("Invalid input!\n");
		break;
	}
}

int CheckPassword(char *password)
{
	int cmpReturn;
	char szDigest[16];
	MD5Digest(password,strlen(password),szDigest);
	char readPwd[40];
	InitializeChar("#password",readPwd);
	printf("%s\n",readPwd);
	//---
	SavePassword("#passwordcheck",szDigest);
	char checkPwd[40];
	InitializeChar("#passwordcheck",checkPwd);
	printf("%s\n",checkPwd);
	cmpReturn=strcmp(readPwd,checkPwd);
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
