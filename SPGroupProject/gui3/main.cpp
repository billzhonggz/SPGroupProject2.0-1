// SPGroupProject
// main.c
#define _CRT_SECURE_NO_WARNINGS
#include "main_gui3.h"

int main()
{
	// Load softwareStatus( whether the first time run this program)
	int softwareStatus = InitializeInt("#softwareStatus");

	// Load debugMode
	int debugMode = InitializeInt("#debugMode");
	if (debugMode) softwareStatus = 1;

	// start
	// !!!Stack Structure!!!
	Entrance(softwareStatus);


	return 0;
}