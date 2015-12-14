#include <stdio.h>
#include <string.h>
#include <windows.h>

int ErrorInformation(char *info)
{
	printf("Error occur in %s()",info);
	exit(0);
	return 0;
}

int InitializeInt(char *variableName)
{
	FILE *fp;
	char temp[30];
	int back;
	int getValue = 0;
    if((fp = fopen("config.dat","r")) != NULL)
	{
		while(fscanf(fp,"%s",&temp) != EOF)
		{
			if(strcmp(temp,variableName) == 0)
			{
				fscanf(fp,"%d",&back);
				getValue = 1;
                break;
			}
		}
		fclose(fp);
		if(getValue) return back;
	}
	else
	{
		printf("Can't load config.dat!");
		exit(0);
	}

	return 0; // can't find value
}

char InitializeChar(char *variableName, char *p)
{
		FILE *fp;
	char temp[30];
	int getValue = 0;
    if((fp = fopen("config.dat","r")) != NULL)
	{
		while(fscanf(fp,"%s",&temp) != EOF)
		{
			if(strcmp(temp,variableName) == 0)
			{
				fscanf(fp,"%s",p);
				getValue = 1;
                break;
			}
		}
		fclose(fp);
		if(getValue) return 1;
	}
	else
	{
		printf("Can't load config.dat!");
		exit(0);
	}

	return 0; // can't find value
}
