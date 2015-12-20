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

void GUI_Entrance(struct items* head)
{
	//Load Login function and verify its return.
	int loginReturn;
	int customerMainReturn;
	int managerMainReturn;
	loginReturn = Login();
	if (loginReturn == 1)
		customerMainReturn = GUI_CustomerMain(head);
	else if (loginReturn == 2)
		managerMainReturn = GUI_ManagerMain();
	else
		ErrorInformation("Login");
	//Verify return value of GUI_CustomerMain.
	int customerNumberReturn;
	if (customerMainReturn == 0)
		ErrorInformation("CustomerMain");
	else if (customerMainReturn == -1)
		Login();
	else
		customerNumberReturn = GUI_CustomerNumber(head, customerMainReturn);
	//Verify return value of GUI_CustomerNumber.
	if (customerNumberReturn == 1)
		GUI_CustomerMain(head);
	else if (customerNumberReturn == 2)
		Login();
	else
		ErrorInformation("CustomerNumber");
	//Verify return value of GUI_ManagerMain.
	int inventoryReturn;
	int priceReturn;
	int itemReturn;
	int pwdReturn;
	if (managerMainReturn == 1)
		inventoryReturn = GUI_ManagerInventory(head);
	else if (managerMainReturn == 2)
		priceReturn = GUI_ManagerPrice(head);
	else if (managerMainReturn == 3)
		itemReturn = GUI_ManagerItem(head);
	else if (managerMainReturn == 4)
		pwdReturn = GUI_ManagerPwd();
	else
		ErrorInformation("ManagerMain");
	//Verify return value of GUI_ManagerInventory.
	if (inventoryReturn)
		GUI_ManagerMain();
	else if (inventoryReturn == 1)
		GUI_ManagerInventory(head);
	else if (inventoryReturn == 2)
		GUI_ManagerMain();
	else if (inventoryReturn == 3)
		Login();
	else
		ErrorInformation("Inventory");
	//Verify return value of GUI_ManagerPrice.
	if (priceReturn)
		GUI_ManagerMain();
	else if (priceReturn == 1)
		GUI_ManagerPrice(head);
	else if (priceReturn == 2)
		GUI_ManagerMain();
	else if (priceReturn == 3)
		Login();
	else
		ErrorInformation("Price");
	//Verify return value of GUI_ManagerItem.
	if (itemReturn)
		GUI_ManagerMain();
	else if (itemReturn == 1)
		GUI_ManagerItem(head);
	else if (itemReturn == 2)
		GUI_ManagerMain();
	else if (itemReturn == 3)
		Login();
	else
		ErrorInformation("Item");
	//Verify return value of GUI_ManagerPwd.
	if (pwdReturn == 1)
		GUI_ManagerMain();
	else if (pwdReturn == 2)
		Login();
	else
		ErrorInformation("Pwd");
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
	int i;
	for (;;)
	{
		scanf("%d", &loginChoice);
		if (loginChoice == 1)
		{
			printf("Debug mode: Go to Customer.\n");
			return 1;
		}
		if (loginChoice == 2)
		{
			int pwdCheck = 0;
			for (;;)
			{
				printf("Please input your password.\n");
				char pwdInput[20];
				for (i = 0; i < 20; i++)
				{
					pwdInput[i] = _getch();
					if (pwdInput[i] == '\r')
						break;
					printf("*");
				}
				pwdInput[i] = '\0';
				if (pwdCheck != CheckPassword(pwdInput))
					printf("\nPassword is incorrect!\n\n");
				else
					break;
			}
			printf("Debug mode: Go to Manager\n");
			return 2;
		}
		else
			printf("Invalid input!\n");
	}	
}

int GUI_CustomerMain(struct items* head)
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
	//Get first address.
	struct items *customerList;
	customerList = head;
	if (customerList==NULL)
		printf("Load item list failed. Please try again.\n");
	printf("We offer these drinks! :)\n");
	printf("ID\tItem\tAmount\tPrice\n");
	printf("0\tExit\n");
	int id=1;
	while (customerList)
	{
		printf("%d\t%s\t%d\t%.2f\n",id,customerList->name,customerList->amount,customerList->price);
		customerList=customerList->next;
		id++;
	}
	//Get user input.
	printf("\n");
	int customerItemChoice;
	for (;;)
	{
		printf("Please input your choice by typing the item number. Type 0 to go back.\n");
		printf("\n");
		printf("YOU CHOOSE:    ");
		scanf("%d", &customerItemChoice);
		if (customerItemChoice == 0)
			return -1;
		else if (customerItemChoice > id)
			printf("Invaild input!\n");
		else
			return customerItemChoice;
	}
}

int GUI_CustomerNumber(struct items* head, int itemID)
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
	customerSearchResult=SearchItem(head,itemID);
	if (customerSearchResult==NULL)
		printf("Invalid input!\n");
	printf("Your choice is %s. Avibile amount is %d. Unit price is %.2f.\n",customerSearchResult->name,customerSearchResult->amount,customerSearchResult->price);
	printf("\n");
	int customerBuyNumber;
	for (;;)
	{
		printf("How many %s you want to buy?\n", customerSearchResult->name);
		printf("NUMBER YOU WANT TO BUY IS  ");
		scanf("%d", &customerBuyNumber);
		printf("\n");
		if (customerBuyNumber > customerSearchResult->amount)
			printf("No enough inventory!\n");
		else
			break;
	}
	double totalPrice;
	totalPrice=CalculatePrice(head,customerBuyNumber,itemID);
	printf("You will buy %d %s. You should pay %.2f in total.\n",customerBuyNumber,customerSearchResult->name,totalPrice);
	printf("\n");
	int paid;
	double change;
	for (;;)
	{
		printf("YOU PAY ");
		scanf("%d", &paid);
		change = paid - totalPrice;
		if (change >= 0)
			break;
		else
			printf("Please pay enough money!\n");
	}
	printf("Change is %.2f, thank you!\n",change);
	if (ChangeAmount(head, -customerBuyNumber, itemID) != 0)
		printf("Error occurss in changing inventory.\n");
	if (StorageItemList(head) != 0)
		printf("Error occurs in storing changing to file.\n");
	//Go back choose.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Buy some other drinks!\n2. Go back to main menu.\n");
	int customerReturn;
	for (;;)
	{
		scanf("%d", &customerReturn);
		if (customerReturn == 1)
			return 1;
		if (customerReturn == 2)
			return 2;
		else
			printf("Invild input!\n");
	}

}

int GUI_ManagerMain()
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
	for (;;)
	{
		scanf("%d", &managerMainInput);
		if (managerMainInput == 1)
			return 1;
		if (managerMainInput == 2)
			return 2;
		if (managerMainInput == 3)
			return 3;
		if (managerMainInput == 4)
			return 4;
		if (managerMainInput == 5)
			return 5;
		else
			printf("Invaild input!\n\nPlease try again.\n");
	}
	
}

int GUI_ManagerInventory(struct items* head)
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
	changeInventory = head;
	int id = 1;
	printf("ID\tItem\tAmount\tPrice\n");
	printf("0\tExit\n");
	while (changeInventory)
	{
		printf("%d\t%s\t%d\t%.2f\n", id, changeInventory->name, changeInventory->amount, changeInventory->price);
		changeInventory = changeInventory->next;
		id++;
	}
	printf("\n");
	//Get user input ID.
	printf("Type ID number to select...\n");
	printf("\n");
	printf("INPUT   \n");
	int changeID;
	scanf("%d", &changeID);
	//Search and print out requesting item.
	if (changeID == 0)
		return 0;
	struct items *beforeChangeItem;
	beforeChangeItem = SearchItem(head, changeID);
	printf("Item you want to change is %s, current inventory is %d.\n", beforeChangeItem->name, beforeChangeItem->amount);
	printf("\n");
	//Change inventory by increase/decrease.
	printf("INPUT CHANGES: INCREASE(POSITIVE INTEGER) / DECREASE(NEGATIVE INTEGER)  ");
	int inventoryChange;
	scanf("%d", &inventoryChange);
	int changeReturn;
	changeReturn = ChangeAmount(head, inventoryChange, changeID);
	if (changeReturn == -1)
		printf("Change inventory failed: ID matching failed.\n");
	if (changeReturn == -2)
		printf("Change inventory failed: No enough initial inventory.\n");
	if (changeReturn == 0)
		printf("Change inventory succeed.\n");
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(head, changeID);
	printf("Store change to file.\n");
	int storeReturn;
	storeReturn = StorageItemList(head);
	if (storeReturn == -1)
		printf("Store to file failed.\n");
	else
		printf("Inventory of item %s has changed to %d.\n", afterChangeItem->name, afterChangeItem->amount);
	printf("\n");
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Change other item(s)' inventory\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	//Exit this function.
	int inventoryBack;
	for (;;)
	{
		scanf("%d", &inventoryBack);
		if (inventoryBack == 1)
			return 1;
		if (inventoryBack == 2)
			return 2;
		if (inventoryBack == 3)
			return 3;
		else
			printf("Invaild input!\n\nPlease try again.\n");
	}
}

int GUI_ManagerPrice(struct items* head)
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
	struct items *managerPrice;
	managerPrice = head;
	int id = 1;
	printf("ID\tItem\tAmount\tPrice\n");
	printf("0\tExit\n");
	while (managerPrice)
	{
		printf("%d\t%s\t%d\t%.2f\n", id, managerPrice->name, managerPrice->amount, managerPrice->price);
		managerPrice = managerPrice->next;
		id++;
	}
	printf("\n");
	//Get user input ID.
	printf("Type ID number to select...\n");
	printf("\n");
	printf("INPUT   \n");
	int changeID;
	scanf("%d", &changeID);
	if (changeID == 0)
		return 0;
	//Search and print out requesting item.
	struct items *beforeChangeItem;
	beforeChangeItem = SearchItem(head, changeID);
	printf("Item you want to change is %s, current price is %.2f.\n", beforeChangeItem->name, beforeChangeItem->price);
	printf("\n");
	//Change price.
	printf("INPUT NEW PRICE  ");
	double priceChange;
	scanf("%lf", &priceChange);
	int changeReturn;
	changeReturn = ChangePrice(head, priceChange, changeID);
	if (changeReturn == -1)
		printf("Change price failed: ID matching failed.\n");
	if (changeReturn == 0)
		printf("Change price succeed.\n");
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(head, changeID);
	int storeReturn;
	storeReturn = StorageItemList(head);
	if (storeReturn == -1)
		printf("Store to file failed.\n");
	else
		printf("Unit price of item %s has changed to %.2f.\n", afterChangeItem->name, afterChangeItem->price);
	printf("\n");
	//Exit this function.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Change other item(s)' price\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	int priceBack;
	for (;;)
	{
		scanf("%d", &priceBack);
		switch (priceBack)
		{
		case 1: return 1;
			break;
		case 2: return 2;
			break;
		case 3: return 3;
			break;
		default: printf("Invalid input!\n");
			break;
		}
	}
}

int GUI_ManagerItem(struct items* head)
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
	for (;;)
	{
		scanf("%d", &itemManegeChoose);
		if (itemManegeChoose == 0)
			return 0;
		else if (itemManegeChoose == 1)
		{
			//Get user input one by one.
			printf("Add a new item\n");
			struct items newItem;
			printf("Input new item name.\n");
			scanf("%s", newItem.name);//Crash here.
			printf("Input new initial inventory.\n");
			scanf("%d", &newItem.amount);
			printf("Input new unit price.\n");
			scanf("%lf", &newItem.price);
			printf("The new item is %s, initial inventory is %d, unit price is %.2f.\n", newItem.name, newItem.amount, newItem.price);
			//Store new item to the dat file.
			printf("Applying your modification...\n");
			int addReturn;
			int storeReturn;
			addReturn = AddItem(head, newItem.name, newItem.amount, newItem.price);
			if (addReturn == -1)
			{
				printf("Item added failed. An existing item has a same name.\n");
				break;
			}
			if (addReturn == 0)
			{
				printf("Item added succeed.\n");
				storeReturn = StorageItemList(head);
				if (storeReturn == -1)
				{
					printf("Store to file failed. Please try again.\n");
					break;
				}

				else
				{
					printf("Store to file succeed.\n");
					printf("\n");
					break;
				}
			}
		}
		else if (itemManegeChoose == 2)
		{
			printf("Delete an item.\n");
			struct items *beforeDel;
			beforeDel = head;
			int id = 1;
			printf("ID\tItem\tAmount\tPrice\n");
			printf("0\tExit\n");
			while (beforeDel)
			{
				printf("%d\t%s\t%d\t%.2f\n", id, beforeDel->name, beforeDel->amount, beforeDel->price);
				beforeDel = beforeDel->next;
				id++;
			}
			printf("\n");
			printf("Input the ID of deleting item.\n");
			printf("\n");
			printf("INPUT ID  ");
			int delID;
			for (;;)
			{
				scanf("%d", &delID);
				if (delID == 0)
					return 0;
				else if (delID<0 || delID>id)
					printf("Your input exceed range.\n");
				else
					break;
			}
			struct items *delConfirm;
			delConfirm = SearchItem(head, delID);
			printf("Item you want to delete is %s. Its inventory is %d. Its unit price is %.2f.\nARE YOU SURE TO DELETE IT?\n", delConfirm->name, delConfirm->amount, delConfirm->price);
			printf("\n");
			printf("1. Confirm\n2. Suspend\n");
			printf("\n");
			printf("INPUT  ");
			int delConfirmInput;
			for (;;)
			{
				scanf("%d", &delConfirmInput);
				if (delConfirmInput == 1)
				{
					int delReturn = DeleteItem(head, delID);
					if (delReturn == 0)
					{
						printf("Target deleted successfully. Now storing to the file.\n");
						int storeReturn = StorageItemList(head);
						if (storeReturn == -1)
						{
							printf("Store to file failed.\n");
							break;
						}
						else
						{
							printf("Store to file succeed.\n");
							printf("\n");
							break;
						}
					}
				}
				if (delConfirmInput == 2)
					return 1;
				else
					printf("Invaild input!\n\nPlease try again.\n");
			}
			
		}
	}
	
	//Exit this function.
	printf("What do you want to do next?\n");
	printf("\n");
	printf("1. Do item management\n2. Go back to manager menu\n3. Go back to main menu\n");
	printf("\n");
	printf("INPUT  ");
	int itemBack;
	for (;;)
	{
		scanf("%d", &itemBack);
		switch (itemBack)
		{
		case 1: return 1;
			break;
		case 2: return 2;
			break;
		case 3: return 3;
			break;
		default: printf("Invalid input!\n");
			break;
		}
	}
}

int GUI_ManagerPwd()
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
	int i;
	for (;;)
	{
		printf("Input current password.\n");
		for (i = 0; i < 20; i++)
		{
			currentPwd[i] = _getch();
			if (currentPwd[i] == '\r')
				break;
			printf("*");
		}
		currentPwd[i] = '\0';
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
	for (;;)
	{
		for (;;)
		{
			printf("Input your new password.\n");
			for (i = 0; i < 20; i++)
			{
				newPwd[i] = _getch();
				if (newPwd[i] == '\r')
					break;
				printf("*");
			}
			newPwd[i] = '\0';
			if (strlen(newPwd)<6 || strlen(newPwd)>20)
				printf("Input a password between 6 to 20 characters!\n\n");
			else break;
		}
		printf("\nInput new password again.\n");
		int i;
		for (i = 0; i < 20; i++)
		{
			newPwdVerify[i] = _getch();
			if (newPwdVerify[i] == '\r')
				break;
			printf("*");
		}
		newPwdVerify[i] = '\0';
		if (strcmp(newPwd, newPwdVerify) != 0)
			printf("Inputs are not same!\n\n");
		else
			break;
	}
	printf("\nStoring your new password...\n\n");
	char szDigest[16];
	MD5Digest(newPwd, strlen(newPwd), szDigest);
	int newPwdStore;
	newPwdStore = SavePassword("#password", szDigest);
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
	for (;;)
	{
		scanf("%d", &pwdBack);
		switch (pwdBack)
		{
		case 1: return 1;
			break;
		case 2: return 2;
			break;
		default: printf("Invalid input!\n");
			break;
		}
	}
}

int CheckPassword(char *password)
{
	int cmpReturn;
	char szDigest[16];
	MD5Digest(password, strlen(password), szDigest);
	char readPwd[40];
	InitializeChar("#password", readPwd);
	//printf("%s\n",readPwd);
	//---
	SavePassword("#passwordcheck", szDigest);
	char checkPwd[40];
	InitializeChar("#passwordcheck", checkPwd);
	//printf("%s\n",checkPwd);
	cmpReturn = strcmp(readPwd, checkPwd);
	if (cmpReturn)
		return 1;
	return 0;
}

struct items *SearchItem(struct items *head, int id)
{
	int i;
	for (i = 0; i<id - 1; i++)
	{
		if (head == NULL)
			return 0;
		head = head->next;
	}
	return head;
}
