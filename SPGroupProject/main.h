//  main.h
//  SPGroupProject
//
//  Copyright (c) 2015 TheBestGroup. All rights reserved.
//
#include <stdio.h>
struct items{
    char name[10];
    int amount;
    double price;
    struct items* next;
};


//Functions Initializing:

    //System functions:
int ErrorInformation(char *info);
		// This function deal with the error information

int InitializeInt(char *variableName);
        // This function load initialize setting from iniFile.
		// If anyone used the globle variable, please contact with Covey.
		// return 0 NOT ERROR.
		// ERROR printf error and exit the program.
char InitializeChar(char *variableName, char *p);
		// Same as above this function get a type of char.
int ChangeConfigInt();
		// use to change config value with type int
        // Return 0 if successfully.
        // Return 1 if errors occured.
int ChangeConfigChar();
		// use to change config value with type char
		// Return 0 if successfully.
        // Return 1 if errors occured.

int FirstSettingPage();
		// used to get administrator username and passworld
		// get initial setting
int CheckPasswrold(char *userName, char passworld);
		// return 0 pass
		// return 1 username or passworld error

struct items *LoadItemList();
        //This function reads the item list from a file and return the address of the first item in the list.
        //Returns:
        //Return the address of the first item if reads the file into memory successfully.
        //Return NULL if can't open the file. File may not exist or is not in the right syntax.

int StorageItemList();
        //This function save the item list in the memory into the file.
        //Returns:
        //Return 0 if saved successfully.
        //Return -1 if can't save the file.
        //Return -2 if any other errors occured.


    //GUI:

int FirstScreen();
		// This function load the first screen(The first time use the program)
		// If it's the first time open this software, load first setting page
        // Augments:
        // int status: 1 if it's the first time open this software, 0 if not.
        // Return:
        // 0: Success.
        // Other: error.

int Login();//Choosing Customer or Manager GUI.
int pwdVerify(char *pwd);//Check password. --By Bill.
void GUI_Customer();//Customer interface.
void GUI_Manager();//Managing interface.
        //Customer and Manager GUI are used to:
        //1. Display the interface continously.
        //2. Read orders.
        //3. Call relative functions to excute the function.
        //4. Display result of the excution to the screen by called fuctions' return values.

    //Items Data Change:

int AddItem(struct items* head,char itemName[], int initialAmount, double initialPrice);
        //This function adds a new good into the end of the list.
        //Augments definition:
            //struct items* head:  The head address of the item list, then change it to the new item's address.
            //char itemName[]:     The name of the new good.
            //int initialAmount:   The initial amount of the good.
            //double initialPrice: The initial Price of the amount.
        //Returns:
            //Return 0:            An good has been added successfully.
            //Return -1:           There is something with exactly the same name.

int DeleteItem(struct items* head,int itemID);
        //This function delete an item from the list basing on the ID inputed.
        //Augments:
            //struct items* head: The head address of the item list, then change it to the deleted item's address.
            //struct items* p:     The address of the item before the deleted item.
            //int itemID:         The itemIDth item need to be deleted, regard the first one's ID as 1.
        //Returns:
            //Return 0:           Successfully delete the target item.
            //Retrun -1:          Can't find the item with the inputed ID.
        //How it work: Search the list for the item with the inputed ID, delete the struct of the item, and link the former and later items together.

int ChangeAmount(struct items* head,int difference, int itemID);
        //This function changes a thing's amount.
        //Augments definition:
            //struct items* head: The head address of the item list, then change it to the amount changed item's address.
            //int difference:     The amount that change, can be negative integer to decrease the amount.
            //int itemID:         The itemIDth item need to be changed the amount, regard the first one's ID as 1.
        //Returns:
            //Return 0:           Changed successfully.
            //Return -1:          Can't find the item with the inputed ID.
            //Return -2:          The amount is not enough to consume.

int ChangePrice(struct items* head,double price, int itemID);
        //This function changes a thing's price.
        //Augments definition:
            //struct items* head: The head address of the item list, then change it to the price changed item's address.
            //int price:          The price after change.
            //int itemID:         The itemIDth item need to be changed the price, regard the first one's ID as 1.
        //Returns:
            //Return 0:           Changed successfully.
            //Return -1:          Can't find the item with the inputed ID.

int ChangeName(struct items* head,char name[], int itemID);
        //This function changes a thing's name.
        //Augments definition:
            //struct items* head: The head address of the item list, then change it to the name changed item's address.
            //char name[]:        The new name to be assigned.
            //int itemID:         The itemIDth item need to be changed the name, regard the first one's ID as 1.
        //Returns:
            //Return 0:           Changed successfully.
            //Return -1:          Can't find the item with the inputed ID.


    //Pays and exchange calculating:
double CalculatePrice(struct items* head,int amount, int itemID);
        //This function calculates one thing's price.
        //Augments definition:
            //struct items* head: The head address of the item list, then change it to the seleted item's address.
            //int amount:         The amount of the target item.
            //int itemID:         The ID of the target item.
        //Returns definition:
            //Return total price: Buy successfully.
            //Return -1:          Can't find the item with the inputed ID.
            //Return -2:          The amount is not enough to consume.

	// Others

int Egg(void);
		// Program printed eggshell
		// hahaha
		// haha
		// ha
        // ......






