#define _CRT_SECURE_NO_WARNINGS
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
	char temp[50];
	int back;
	int getValue = 0;
    if((fp = fopen("config.dat","r")) != NULL)
	{
		while(fscanf(fp,"%s",temp) != EOF)
		{
			if(strcmp(temp,variableName) == 0)
			{
				fscanf(fp,"%d",&back);
				getValue = 1;
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

int InitializeChar(char *variableName, char *p)
{
		FILE *fp;
	char temp[50];
	int getValue = 0;
    if((fp = fopen("config.dat","r")) != NULL)
	{
		while(fscanf(fp,"%s",temp) != EOF)
		{
			if(strcmp(temp,variableName) == 0)
			{
				fscanf(fp,"%s",p);
				getValue = 1;
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

int ChangeConfigInt(char *variableName, int value)
{
	FILE *fp;
	FILE *tempfile;
	char temp[50];
	if(( fp = fopen("config.dat","r"))  && ( tempfile = fopen("temp.dat","w+")))
	{
		while(fscanf(fp,"%s",temp) != EOF)
		{
			if(strcmp(temp,variableName))
				// not find 
			{
				fprintf(tempfile,"%s",temp);
				if(fgets(temp,50,fp) != NULL)
				{
					fputs(temp,tempfile);
				}	
			}
			else // had find v.
			{
				fprintf(tempfile,"%s",temp);
				fprintf(tempfile," %d\n",value);
				fscanf(fp,"%s",temp);
			}
			//fprintf(tempfile,"%c",'\0');
			
		}

		fclose(fp);
		fclose(tempfile);

		if((fp = fopen("config.dat","w")) && (tempfile = fopen("temp.dat","r")))
		{
			while( fgets(temp,50,tempfile) != NULL)
			{
				fputs(temp,fp);
			}
		}
		else
		{
			//printf("error in changeint");
			return 1; // error
		}
		fclose(fp);
		fclose(tempfile);
		remove("temp.dat");
		
		return 0; // not error
	}
	else
	{
		return 1; // error
	}
}
int ChangeConfigChar(char *variableName, char *p)
{
	FILE *fp;
	FILE *tempfile;
	char temp[50];
	if(( fp = fopen("config.dat","r"))  && ( tempfile = fopen("temp.dat","w+")))
	{
		while(fscanf(fp,"%s",temp) != EOF)
		{
			if(strcmp(temp,variableName))
				// not find 
			{
				fprintf(tempfile,"%s",temp);
				if(fgets(temp,50,fp) != NULL)
				{
					fputs(temp,tempfile);
				}	
			}
			else // had find v.
			{
				fprintf(tempfile,"%s",temp);
				fprintf(tempfile," %s\n",p);
				fscanf(fp,"%s",temp);
			}
			//fprintf(tempfile,"%c",'\0');
			
		}

		fclose(fp);
		fclose(tempfile);

		if((fp = fopen("config.dat","w")) && (tempfile = fopen("temp.dat","r")))
		{
			while( fgets(temp,50,tempfile) != NULL)
			{
				fputs(temp,fp);
			}
		}
		else
		{
			//printf("error in changeint");
			return 1; // error
		}
		fclose(fp);
		fclose(tempfile);
		remove("temp.dat");
		return 0; // not error 
	}
	else
	{
		return 1; // error
	}
}
int SavePassword(char *variableName, char *p)
{
	FILE *fp;
	FILE *tempfile;
	char temp[50];
	if(( fp = fopen("config.dat","r"))  && ( tempfile = fopen("temp.dat","w+")))
	{
		while(fscanf(fp,"%s",temp) != EOF)
		{
			if(strcmp(temp,variableName))
				// not find 
			{
				fprintf(tempfile,"%s",temp);
				if(fgets(temp,50,fp) != NULL)
				{
					fputs(temp,tempfile);
				}	
			}
			else // had find v.
			{
				fprintf(tempfile,"%s",temp);
				//----------------  
				fprintf (tempfile,"%c",' ');
				int i;
				for (i=0;i<16;i++) 
				{
					fprintf (tempfile,"%02X",(unsigned char)(p[i]));
				}
				fprintf (tempfile,"\n");
				fscanf(fp,"%s",temp);
			}
			//fprintf(tempfile,"%c",'\0');
			
		}

		fclose(fp);
		fclose(tempfile);

		if((fp = fopen("config.dat","w")) && (tempfile = fopen("temp.dat","r")))
		{
			while( fgets(temp,50,tempfile) != NULL)
			{
				fputs(temp,fp);
			}
		}
		else
		{
			//printf("error in changeint");
			return 1; // error
		}
		fclose(fp);
		fclose(tempfile);
		remove("temp.dat");
		return 0; // not error 
	}
	else
	{
		return 1; // error
	}
}


