#ifndef _COMMANDS_H
#define _COMMANDS_H
#include <unistd.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_LINE_SIZE 80
#define MAX_ARG 20
int ExeComp(char* lineSize);
int BgCmd(char* lineSize, void* jobs);
<<<<<<< HEAD
int ExeCmd(char* lineSize, char* cmdString);
void ExeExternal(char *args[MAX_ARG], char* cmdString);

=======
int ExeCmd(void* jobs, char* lineSize, char* cmdString);
void ExeExternal(char *args[MAX_ARG], char* cmdString);
//Dror
typedef struct job
{
	int serial_num;
	char* name;
	int pid;
	time_t start_time;
}job;
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
#endif

