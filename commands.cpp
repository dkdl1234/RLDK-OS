//commands.c
//********************************************
#include "commands.h"
//********************************************
// function name: ExeCmd
// Description: interperts and executes built-in commands
// Parameters: pointer to jobs, command string
// Returns: 0 - success,1 - failure
//**************************************************************************************
int ExeCmd(void* jobs, char* lineSize, char* cmdString)
{
	char* cmd; 
	char* args[MAX_ARG];
	char pwd[MAX_LINE_SIZE];
	char* delimiters = " \t\n";  
	int i = 0, num_arg = 0;
	bool illegal_cmd = false; // illegal command
	//Extract the command
    cmd = strtok(lineSize, delimiters);
	if (cmd == NULL)
		return 0; 
   	args[0] = cmd;
	for (i=1; i<MAX_ARG; i++)
	{
		//when giving NULL as parameter strtok return the next word till the end of string
		args[i] = strtok(NULL, delimiters); 
		if (args[i] != NULL) 
			num_arg++; 
 
	}
/*************************************************/
// Built in Commands PLEASE NOTE NOT ALL REQUIRED
// ARE IN THIS CHAIN OF IF COMMANDS. PLEASE ADD
// MORE IF STATEMENTS AS REQUIRED
/*************************************************/
	//Dror
	if (!strcmp(cmd, "cd") ) 
	{
		if (num_arg != 1)
		{
			fprintf (stderr,"smash error: > \"%s\"\n", cmdString);//check in PDF what to print
			return 1;
		}
		else
		{
			if  (args[1] == "-") //like cd.. - change to "father" working directory (if it exist) and print it.
			{
				if (father_wd == "/0")//there is no "father" working directory
				{
					fprintf (stderr,"smash error: > \"%s\"\n", cmdString);//check in PDF what to print
					return 1;
				}
				else
				{
					chdir(father_wd);
					printf("%s\n", father_wd);
				}
			}
			else // change to args[1] working directory
			{
				//update "father" working directory to be the current directory before changing directory
				getcwd(pwd, sizeof(pwd));//check what it return in failure and perror
				strcpy(father_wd,pwd);
				chdir(args[1]);//change current directory
			}
		}
		return 0;
	} 
	
	/*************************************************/
	//Dror
	else if (!strcmp(cmd, "pwd")) 
	{
		if (num_arg != 0)
		{
			fprintf (stderr,"smash error: > \"%s\"\n", cmdString);
			return 1;
		}
		else
		{
			getcwd(pwd, sizeof(pwd));//check what it return in failure and perror
			printf("%s\n", pwd);
			return 0;
		}
	}
	
	/*************************************************/
	//Dror
	else if (!strcmp(cmd, "mkdir"))
	{
		//Not Required.
	}
	/*************************************************/
	
	else if (!strcmp(cmd, "jobs")) 
	{
 		// wait for Dror - idea - let's hold a list (or vector) of struct/class of jobs (we need to think on the fields- Serial_num,name,PID,start_time,...)
		//in this function we just need to print the list.
	}
	//dror
	/*************************************************/
	else if (!strcmp(cmd, "showpid")) 
	{
		if (num_arg != 0)
		{
			fprintf (stderr,"smash error: > \"%s\"\n", cmdString);
			return 1;
		}
		else
		{
			printf("smash pid is %d\n",getpid());//check what happen if getpid() failed
			return 0;
		}
	}
	/*************************************************/
	else if (!strcmp(cmd, "fg")) 
	{
		
	} 
	/*************************************************/
	else if (!strcmp(cmd, "bg")) 
	{
  		
	}
	/*************************************************/
	else if (!strcmp(cmd, "quit"))
	{
   		
	} 
	/*************************************************/
	else // external command
	{
 		ExeExternal(args, cmdString);
	 	return 0;
	}
	if (illegal_cmd == true)
	{
		printf("smash error: > \"%s\"\n", cmdString);
		return 1;
	}
    return 0;
}
//**************************************************************************************
// function name: ExeExternal
// Description: executes external command
// Parameters: external command arguments, external command string
// Returns: void
//**************************************************************************************
void ExeExternal(char *args[MAX_ARG], char* cmdString)
{
	int pID;
    switch(pID = fork()) 
	{
    		case -1: 
					// Add your code here (error)
					perror("Error fork:");
					exit(1);
        	case 0 :
                	// Child Process
               		setpgrp();
					
			        // Add your code here (execute an external command)
					
			//pID = Child Process ID
			default:
                	// Father Process
					exit(1);

	}
}
//**************************************************************************************
// function name: ExeComp
// Description: executes complicated command
// Parameters: command string
// Returns: 0- if complicated -1- if not
//**************************************************************************************
int ExeComp(char* lineSize)
{
	char ExtCmd[MAX_LINE_SIZE+2];
	char *args[MAX_ARG];
    if ((strstr(lineSize, "|")) || (strstr(lineSize, "<")) || (strstr(lineSize, ">")) || (strstr(lineSize, "*")) || (strstr(lineSize, "?")) || (strstr(lineSize, ">>")) || (strstr(lineSize, "|&")))
    {
		// Add your code here (execute a complicated command)
					
		/* 
		your code
		*/
	} 
	return -1;
}
//**************************************************************************************
// function name: BgCmd
// Description: if command is in background, insert the command to jobs
// Parameters: command string, pointer to jobs
// Returns: 0- BG command -1- if not
//**************************************************************************************
int BgCmd(char* lineSize, void* jobs)
{

	char* Command;
	char* delimiters = " \t\n";
	char *args[MAX_ARG];
	if (lineSize[strlen(lineSize)-2] == '&')
	{
		lineSize[strlen(lineSize)-2] = '\0';
		// Add your code here (execute a in the background)
					
		/* 
		your code
		*/
		
	}
	return -1;
}

