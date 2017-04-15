/*	smash.c
main file. This file contains the main function of smash
*******************************************************************/
using namespace std;//Dror

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "commands.h"
#include "signals.h"
#include <vector>//Dror
#define MAX_LINE_SIZE 80
#define MAXARGS 20

char* L_Fg_Cmd;
<<<<<<< HEAD
char lineSize[MAX_LINE_SIZE]; 
=======
vector <job>  jobs; //= NULL; //This represents the list of jobs. Please change to a preferred type (e.g array of char*)
char lineSize[MAX_LINE_SIZE]; 
char father_wd[MAX_LINE_SIZE];//This represent the "father" directory of the current working dierctory (for "cd -" command)-Dror.
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
//**************************************************************************************
// function name: main
// Description: main function of smash. get command from user and calls command functions
//**************************************************************************************
int main(int argc, char *argv[])
{
    char cmdString[MAX_LINE_SIZE]; 	   

	
	//signal declaretions
	//NOTE: the signal handlers and the function/s that sets the handler should be found in siganls.c
	 /* add your code here */
	
	/************************************/
	//NOTE: the signal handlers and the function/s that sets the handler should be found in siganls.c
	//set your signal handlers here
	/* add your code here */

	/************************************/

	/************************************/
	// Init globals 


	
	L_Fg_Cmd =(char*)malloc(sizeof(char)*(MAX_LINE_SIZE+1));
	if (L_Fg_Cmd == NULL) 
			exit (-1); 
	L_Fg_Cmd[0] = '\0';
	
    	while (1)
    	{
    	//smash is waiting for a new cmd
	 	printf("smash > ");
	 	//get full line from user
		fgets(lineSize, MAX_LINE_SIZE, stdin);
		strcpy(cmdString, lineSize);    	
		cmdString[strlen(lineSize)-1]='\0';
		// perform a complicated Command
		if(!ExeComp(lineSize)) continue; 
<<<<<<< HEAD
		ExeCmd(lineSize, cmdString);
=======
		// background command
	 	if(!BgCmd(lineSize, jobs)) continue; 
		// built in commands
		ExeCmd(jobs, lineSize, cmdString);
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
		
		/* initialize for next line read*/
		lineSize[0]='\0';
		cmdString[0]='\0';
	}
    return 0;
}

