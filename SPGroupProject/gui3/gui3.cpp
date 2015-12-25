//  gui.cpp by Bill.
//  gui3.cpp modified by Covey Dec. 24
//  Last modification on Dec. 15th, 2015
//  MD5 algrithm from http://blog.csdn.net/qinggebuyao/article/details/7995398
//  Functions waiting for implementation are listed below...
//	Password length limitation.(Finished)
//	Password input failure information.(Finished)
//	Password encryption.(Finished)
//  Password hide.

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"main_gui3.h"
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

	
	//while (1)
	

			printf("Please input your manage password which is between 6 to 16 characters.\n");
			// print * when password input
			
			
	char pwdInput[17];
	char pwdVerify[17];
	int pwdGet = 0;
	int i;
	//int j;
	int k;
	while (1)
	{
		while (1)
		{
			i = 0;
			printf("Please input your password.\n");
			while (1)
			{
				if (i > 16) i = 16;
				pwdInput[i] = _getch();
				if (pwdInput[i] == '\r')
				{
					break;
				}
				k = i;
				//printf("pwdInput[i] = %c\n", pwdInput[i]);
				//printf("i = %d\n", i);
				if (pwdInput[i] == 8 && i != 0)
				{
					printf("\b \b");
					i--;
					i--;
				}
				else if (pwdInput[i] == 8 && i == 0)
				{
					i--;
				}
				if (pwdInput[k] != 8 && i < 16)
				{
					printf("*");
				}
				i++;
			}

			pwdInput[i] = '\0';
			if (strlen(pwdInput) < 6 || strlen(pwdInput) > 16)
			{
				printf("\nPassword format error!\n");
			}
			else
			{
				break;
			}
		}



		printf("\nPlease input your password again.\n");

		while (1)
		{
			i = 0;
			//printf("Please input your password.\n");
			while (1)
			{
				if (i > 16) i = 16;
				pwdVerify[i] = _getch();
				if (pwdVerify[i] == '\r')
				{
					break;
				}
				k = i;
				//printf("pwdInput[i] = %c\n", pwdInput[i]);
				//printf("i = %d\n", i);
				if (pwdVerify[i] == 8 && i != 0)
				{
					printf("\b \b");
					i--;
					i--;
				}
				else if (pwdVerify[i] == 8 && i == 0)
				{
					i--;
				}
				if (pwdVerify[k] != 8 && i < 16)
				{
					printf("*");
				}
				i++;
			}

			pwdVerify[i] = '\0';
			if (strcmp(pwdVerify, pwdVerify) != 0)
			{
				printf("\nInputs are not same!\n\n");
				break;
			}
			else
			{
				pwdGet = 1;
				break;
			}

		}
		if (pwdGet) break;
	}


	
	printf("\nEncrypting your password...\n\n");
	char szDigest[16];
	MD5Digest(pwdInput,strlen(pwdInput),szDigest);
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

int Login(struct items *head)
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
	printf("0. Exit\n");
	printf("\n");
	printf("1. Customer\n");
	printf("\n");
	printf("2. Manager\n");
	printf("\n");
	printf("Please input your choice.\n");
	int loginChoice;
	while (1)
	{
		scanf("%d",&loginChoice);
		char c;
		// empty io buffer
		while ((c = getchar()) != '\n' && c != EOF);
		if (loginChoice == 0) exit(0);
		if (loginChoice == 1 || loginChoice == 2 )
		{
			break;
		}
		else
		{
			printf("Invalid Input!Please input again!\n");
		}
	}

	if (loginChoice==1)
	{
		system("cls");
		//printf("Debug mode: Go to Customer.\n");
		//
		return 1;//call GUI_CustomerMain(head);
	}
	if (loginChoice==2)
	{
		int pwdCheck=0;
		int i,k;
		char pwdInput[17];

		while (1)
		{
			i = 0;
			printf("Please input your password.\n");
			while (1)
			{
				if (i > 16) i = 16;
				pwdInput[i] = _getch();
				if (pwdInput[i] == '\r')
				{
					break;
				}
				k = i;
				//printf("pwdInput[i] = %c\n", pwdInput[i]);
				//printf("i = %d\n", i);
				if (pwdInput[i] == 8 && i != 0)
				{
					printf("\b \b");
					i--;
					i--;
				}
				else if (pwdInput[i] == 8 && i == 0)
				{
					i--;
				}
				if (pwdInput[k] != 8 && i < 16)
				{
					printf("*");
				}
				i++;
			}

			pwdInput[i] = '\0';
			if (pwdCheck != CheckPassword(pwdInput))
				printf("\nPassword is incorrect!\n\n");
			else
				break;
		}
		return 2;// GUI_ManagerMain(head);
	}
	else 
		return -1;
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
	printf("0\tGo back\n");
	int id = 1;
	while (customerList)
	{
		printf("%d\t%s\t%d\t%.2f\n",id,customerList->name,customerList->amount,customerList->price);
		customerList=customerList->next;
		id++;
	}
	id--;
	//printf("id = %d",id);
	//Get user input.
	printf("\n");
	int customerItemChoice = -1;
	//for (;;)
	{
		printf("Please input your choice by typing the item number. Type 0 to go back.\n");
		printf("\n");
		printf("YOU CHOOSE:    ");
		while(1)
		{
			scanf("%d", &customerItemChoice);
			if (customerItemChoice == 0)
			{
				return 0;
				//Login(head);
			}
			else if(customerItemChoice > id || customerItemChoice <0)
			{
				printf("Invaild input! Please input again!\n");
				char c;
				// empty io buffer
				while((c = getchar()) != '\n' && c != EOF);
			}
			else
			{
				//GUI_CustomerNumber(head,customerItemChoice);
				return customerItemChoice;
				break;
			}
		}
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
	// if (customerSearchResult==NULL)
	//	printf("Invalid input!\n");
	printf("Your choice is %s. Avibile amount is %d. Unit price is %.2f.\n",customerSearchResult->name,customerSearchResult->amount,customerSearchResult->price);
	printf("\n");
	int customerBuyNumber = -1;
	while(1)
	{
		printf("How many %s you want to buy?\n", customerSearchResult->name);
		printf("NUMBER YOU WANT TO BUY IS  ");
		scanf("%d", &customerBuyNumber);
		char c;
		while((c = getchar()) != '\n' && c != EOF);
		printf("\n");
		if (customerBuyNumber <= 0)
		{
			printf("Input Invalid! Please input again!\n");
		}
		else if (customerBuyNumber > customerSearchResult->amount )
		{
			printf("No enough inventory!\n Please input again!\n");
			//printf("customerBuyNumber = %d",customerBuyNumber);
		}
		else
			break;
	}
	double totalPrice;
	totalPrice=CalculatePrice(head,customerBuyNumber,itemID);
	printf("You will buy %d %s. You should pay %.2f in total.\n",customerBuyNumber,customerSearchResult->name,totalPrice);
	printf("\n");
	double paid;
	double change;
	while(1)
	{
		printf("YOU PAY : \n");
		scanf("%lf", &paid);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
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
	printf("0. Go back to main menu.\n1. Buy some other drinks!\n");
	int customerReturn;
	while (1)
	{
		scanf("%d",&customerReturn);
		char c;
		// empty io buffer
		while ((c = getchar()) != '\n' && c != EOF);
		switch (customerReturn)
		{
			case 0: return 0;//GUI_CustomerMain(head);
				break;
			case 1: return 1;//Login(head);
				break;
			default : printf("Invalid input!Please input again\n");
		}
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
	printf("0. Go back to main menu\n\n1. Change inventory\n\n2. Change unit price\n\n3. Add & delete items\n\n4. Change password\n\n");
	//printf("\n");
	printf("INPUT : ");
	int managerMainInput;
	while (1)
	{
		scanf("%d",&managerMainInput);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		switch (managerMainInput)
		{
			case 0: return 0; // Login(head);
				break;
			case 1: return 1; // GUI_ManagerInventory(head)/*printf("Debug mode: Go to submenu inventory.\n")*/;
				break;
			case 2: return 2; // GUI_ManagerPrice(head)/*printf("Debug mode: Go to submenu price.\n")*/;
				break;
			case 3: return 3; // GUI_ManagerItem(head)/*printf("Debug mode: Go to submenu item.\n")*/;
				break;
			case 4: return 4; // GUI_ManagerPwd(head)/*printf("Debug mode: Go to submenu password.\n")*/;
				break;
			default: printf("\nInvalid input!Please input again\nINPUT : ");
		}
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
	printf("0\tGo back\n");
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

	while (1)
	{
		scanf("%d", &changeID);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		if (changeID < 0 || changeID > id - 1)
		{
			printf("\nInvalid Input! Please input again\n");
		}
		else
		{
			break;
		}

	}
	
	//Search and print out requesting item.
	if (changeID == 0)
	{
		return 1;//GUI_ManagerMain();
	}
		
	struct items *beforeChangeItem;
	beforeChangeItem = SearchItem(head,changeID);
	printf("Item you want to change is %s, current inventory is %d.\n", beforeChangeItem->name, beforeChangeItem->amount);
	printf("\n");

	//Change inventory by increase/decrease.
	printf("INPUT CHANGES: INCREASE(POSITIVE INTEGER) / DECREASE(NEGATIVE INTEGER)\n");
	int inventoryChange;
	while (1)
	{
		scanf("%d", &inventoryChange);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		int changeReturn = 0;
		changeReturn = ChangeAmount(head, inventoryChange, changeID);
		if (inventoryChange == 0)
		{
			printf("Invalid Input! Please input again\n");
		}
		else if (changeReturn == -1)
		{
			printf("Change inventory failed: ID matching failed.\n");
			ErrorInformation("ChangeAmount");
		}
		else if (changeReturn == -2)
		{
			printf("Change inventory failed: No enough initial inventory.\n Pleasse input again\n");
		}
		else if (changeReturn == 0)
		{
			printf("Change inventory succeed.\n");
			break;
		}
			
		
	}
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(head,changeID);
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
	printf("0. Go back to main menu\n1. Go back to manager menu\n2. Change other item(s)' inventory\n");
	printf("\n");
	printf("INPUT  ");
	//Exit this function.
	int inventoryBack = -1;
	while (1)
	{
		scanf("%d", &inventoryBack);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		switch (inventoryBack)
		{
			case 0: return 0;// Login(head);
				break;
			case 1: return 1;// GUI_ManagerMain();
				break;
			case 2: return 2;// GUI_ManagerInventory(head);
				break;
			default: printf("Invalid Input!Please Input again\n");
				break;
		}
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
	printf("0\tGo back\n");
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
	printf("INPUT   ");
	int changeID = -1;
	while (1)
	{
		scanf("%d", &changeID);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		if (changeID == 0)
		{
			return 1;// GUI_ManagerMain();
		}
		else if (changeID < 0 || changeID >= id)
		{
			printf("Invalid Input!Please input again\n");
		}
		else
		{
			break;
		}

	}
	
	//Search and print out requesting item.
	struct items *beforeChangeItem;
	beforeChangeItem = SearchItem(head,changeID);
	printf("Item you want to change is %s, current price is %.2f.\n", beforeChangeItem->name, beforeChangeItem->price);
	printf("\n");
	//Change price.
	printf("INPUT NEW PRICE  ");
	double priceChange = -1;
	while (1)
	{
		scanf("%lf", &priceChange);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
	    if (priceChange <= 0)
		{
			printf("Invalid Input!Please input again\n");
		}
		else
		{
			break;
		}
	}
	
	int changeReturn;
	changeReturn = ChangePrice(head, priceChange, changeID);
	if (changeReturn == -1)
		printf("Change price failed: ID matching failed.\n");
	if (changeReturn == 0)
		printf("Change price succeed.\n");
	//Print out changed item to show result.
	struct items *afterChangeItem;
	afterChangeItem = SearchItem(head,changeID);
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
	printf("0. Go back to main menu\n1. Go back to manager menu\n2. Change other item(s)' price\n");
	printf("\n");
	printf("INPUT  ");
	int priceBack; 
	while (1)
	{
		scanf("%d", &priceBack);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);	
		switch (priceBack)
		{
			case 0: return 0;// Go back Login(head);
				break;
			case 1: return 1;// GUI_ManagerMain();
				break;
			case 2: return 2;// GUI_ManagerPrice(head);
				break;
			case 3: 
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
	printf("0. Go back\n1. Add a new item\n2. Delete an existing item\n");
	printf("\n");
	printf("INPUT  ");
	int itemManegeChoose = -1;
	while (1)
	{
		scanf("%d", &itemManegeChoose);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		if (itemManegeChoose == 0)
		{
			return 0;
		}
		else if (itemManegeChoose == 1 || itemManegeChoose == 2)
		{
			break;
		}
		else
		{
			printf("Invalid Input!Please input again!");
		}

	}

	if (itemManegeChoose == 1)
	{
		//Get user input one by one.
		printf("Add a new item\n");
		struct items newItem;
		printf("Input new item name.\n");
		scanf("%s", newItem.name);//Crash here.
		printf("Input new initial inventory.\n");
		newItem.amount = -1;
		while (1)
		{
			scanf("%d", &newItem.amount);
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			if (newItem.amount < 0)
			{
				printf("Invalid Input!Please input again!");
			}
			else
			{
				break;
			}
		}
		printf("Input new unit price.\n");
		newItem.price = -1;
		while (1)
		{
			scanf("%lf", &newItem.price);
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			if (newItem.amount < 0)
			{
				printf("Invalid Input!Please input again!");
			}
			else
			{
				break;
			}
		}
		printf("The new item is %s, initial inventory is %d, unit price is %.2f.\n", newItem.name, newItem.amount, newItem.price);
		//Store new item to the dat file.
		printf("Applying your modification...\n");
		int addReturn;
		int storeReturn;
		addReturn = AddItem(head, newItem.name, newItem.amount, newItem.price);
		if (addReturn == -1)
		{
			printf("Item added failed. An existing item has a same name.\n");
			//return 0;
		}
		if (addReturn == 0)
		{
			printf("Item added succeed.\n");
			storeReturn = StorageItemList(head);
			if (storeReturn == -1)
				printf("Store to file failed.\n");
			else
				printf("Store to file succeed.\n");
			printf("\n");
			//return 1;
		}
	}
	if (itemManegeChoose == 2)
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
		int delID = -1;
		while (1)
		{
			scanf("%d", &delID);
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			if (delID < 0 || delID >= id)
			{
				printf("Invalid Input!Please input again!");
			}
			else
			{
				break;
			}
		}
		
		if (delID == 0)
		{
			return 0; // GUI_ManagerMain();
		}
			
		struct items *delConfirm;
		delConfirm = SearchItem(head,delID);
		printf("Item you want to delete is %s. Its inventory is %d. Its unit price is %.2f.\nARE YOU SURE TO DELETE IT?\n", delConfirm->name, delConfirm->amount, delConfirm->price);
		printf("\n");
		printf("1. Confirm\n2. Suspend\n");
		printf("\n");
		printf("INPUT  ");
		int delConfirmInput = -1;
		while (1)
		{
			scanf("%d", &delConfirmInput);
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			if (delConfirmInput == 1 || delConfirmInput == 2)
			{
				break;
			}
			else
			{
				printf("Invalid Input!Please input again!");
			}
		}
		
		if (delConfirmInput == 1)
		{
			int delReturn = DeleteItem(head, delID);
			if (delReturn == 0)
			{
				printf("Target deleted successfully. Now storing to the file.\n");
				int storeReturn = StorageItemList(head);
				if (storeReturn == -1)
					printf("Store to file failed.\n");
				else
					printf("Store to file succeed.\n");
				printf("\n");
			}
		}
		if (delConfirmInput == 2)
		{
			return 0; // GUI_ManagerItem(head);
		}
			
	}
	//Exit this function.-------------------------------------------------------------------------------------------------------------------------
	printf("What do you want to do next?\n");
	printf("\n");
	printf("0. Go back to main menu\n1. Go back to manager menu\n2. Do item management\n");
	printf("\n");
	printf("INPUT  ");
	int itemBack = -1;
	
	while (1)
	{
		scanf("%d", &itemBack);
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
		if (itemBack == 0 || itemBack == 1 || itemBack == 2)
		{
			break;
		}
		else
		{
			printf("Invalid Input!Please input again!");
		}
	}
	switch (itemBack)
	{
	case 0: return 1; // Login(head);
		break;
	case 1: return 0; // GUI_ManagerItem(head);
		break;
	case 2: return 3; // GUI_CustomerMain(head);
		break;
	default: printf("Invalid input!\n");
		break;
	}
}

int  GUI_ManagerPwd(struct items* head)
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
	char currentPwd[17];
	int i,k;
	int pwdSet = 0;



	while (1)
	{
		i = 0;
		printf("Please input your password.\n");
		while (1)
		{
			if (i > 16) i = 16;
			currentPwd[i] = _getch();
			if (currentPwd[i] == '\r')
			{
				break;
			}
			k = i;
			//printf("pwdInput[i] = %c\n", pwdInput[i]);
			//printf("i = %d\n", i);
			if (currentPwd[i] == 8 && i != 0)
			{
				printf("\b \b");
				i--;
				i--;
			}
			else if (currentPwd[i] == 8 && i == 0)
			{
				i--;
			}
			if (currentPwd[k] != 8 && i < 16)
			{
				printf("*");
			}
			i++;
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



	/*
	while (1)
	{
		printf("Input current password.\n");
		i = 0;
		while (1)
		{
			if (i > 16) i = 16;
			currentPwd[i] = _getch();
			if (currentPwd[i] == '\r')
			{
				break;
			}
			else if (i < 16)
			{
				printf("*");
			}
			i++;
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
		*/

	char newPwd[17];
	char newPwdVerify[17];

	while (1)
	{
		i = 0;
		printf("\nInput new password.\n");
		while (1)
		{
			if (i > 16) i = 16;
			newPwd[i] = _getch();
			if (newPwd[i] == '\r')
			{
				break;
			}
			k = i;
			//printf("pwdInput[i] = %c\n", pwdInput[i]);
			//printf("i = %d\n", i);
			if (newPwd[i] == 8 && i != 0)
			{
				printf("\b \b");
				i--;
				i--;
			}
			else if (newPwd[i] == 8 && i == 0)
			{
				i--;
			}
			if (newPwd[k] != 8 && i < 16)
			{
				printf("*");
			}
			i++;
		}

		newPwd[i] = '\0';
		if (strlen(newPwd) < 6 || strlen(newPwd) > 20)
		{
			printf("\nInput a password between 6 to 20 characters!\n");
			continue;
		}
		
		while (1)
		{
			i = 0;
			printf("\nInput new password again.\n");
			while (1)
			{
				if (i > 16) i = 16;
				newPwdVerify[i] = _getch();
				if (newPwdVerify[i] == '\r')
				{
					break;
				}
				k = i;
				//printf("pwdInput[i] = %c\n", pwdInput[i]);
				//printf("i = %d\n", i);
				if (newPwdVerify[i] == 8 && i != 0)
				{
					printf("\b \b");
					i--;
					i--;
				}
				else if (newPwdVerify[i] == 8 && i == 0)
				{
					i--;
				}
				if (newPwdVerify[k] != 8 && i < 16)
				{
					printf("*");
				}
				i++;
			}

			newPwdVerify[i] = '\0';
			if (strcmp(newPwd, newPwdVerify) != 0)
				printf("\nInputs are not same!\n\n");
			else
			{
				pwdSet = 1;
				break;
			}
			
		}
		if (pwdSet) break;


		/*
		while (1)
		{
			printf("\nInput new password again.\n");
			i = 0;
			while (1)
			{
				if (i > 16) i = 16;
				newPwdVerify[i] = _getch();
				if (newPwdVerify[i] == '\r')
				{
					break;
				}
				else if (i < 16)
				{
					printf("*");
				}
				i++;
			}
			newPwdVerify[i] = '\0';
			if (strcmp(newPwd, newPwdVerify) != 0)
				printf("\nInputs are not same!\n\n");
			else
			{
				pwdSet = 1;
				break;
			}
				
		}
		if (pwdSet)
		{
			break;
		}
			
		
*/

	}
	printf("\nStoring your new password...\n\n");
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
	printf("0. Go back to main menu\n1. Go back to manager menu\n");
	printf("\n");
	printf("INPUT  ");
	int pwdBack = -1;
	while (1)
	{
		scanf("%d", &pwdBack);
		char c;
		while((c = getchar()) != '\n' && c != EOF);
		switch (pwdBack)
		{
		case 0: return 0; // Login(head);
			break;
		case 1: return 1; // GUI_ManagerMain();
			break;
		default: printf("\nInvalid input!Please input again\n");
			break;
		}
	}

}

int CheckPassword(char *password)
{
	int cmpReturn;
	char szDigest[16];
	MD5Digest(password,strlen(password),szDigest);
	char readPwd[40];
	InitializeChar("#password",readPwd);
	//printf("%s\n",readPwd);
	//---
	SavePassword("#passwordcheck",szDigest);
	char checkPwd[40];
	InitializeChar("#passwordcheck",checkPwd);
	//printf("%s\n",checkPwd);
	cmpReturn=strcmp(readPwd,checkPwd);
	if (cmpReturn)
		return 1;
	return 0;
}


struct items *SearchItem(struct items *head, int id)
{
	int i;
	for (i=0;i<id-1;i++)
	{
		if (head == NULL)
			return 0;
		head=head->next;
	}
	return head;
}
