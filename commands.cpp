//commands.c
//********************************************
#include "commands.h"
<<<<<<< HEAD
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#define MAX_NUM_JOBS 100
#define MAX_HISTORY_LENGTH 50

using namespace std;
char father_wd[MAX_LINE_SIZE];//This represent the "father" directory of the current working dierctory (for "cd -" command)-Dror.

/*TODO: add support for background and foreground job assignment, implement complex execution and external commands*/

//**************************************************Our Classes*********************************************************************
//class representing a job's metadata
class job {
public: //ctor's
	job(unsigned serial_num, const char* name, int pid, time_t start_time) : 	m_serial_num(serial_num),
																				m_name(name),
																				m_pid(pid),
																				m_start_time(start_time) {}
	//cp ctor
	job(const job& cjob) : 	m_serial_num(cjob.m_serial_num),
							m_name(cjob.m_name),
							m_pid(cjob.m_pid),
							m_start_time(cjob.m_start_time){}

public: //API
	unsigned SerialNum() const{ return m_serial_num; }
	string Name() const { return m_name; }
	int ProcessID() const { return m_pid; }
	time_t StartTime() const { return m_start_time; }

private:
	unsigned m_serial_num;
	string m_name;
	int m_pid;
	time_t m_start_time;

	friend class JobCmpFN;
};

//helper functor for finding a job using a process ID
class JobCmpFn {
public:
	JobCmpFn(int pid = 0) : m_pid(pid){}
	bool operator()(job const& job_) {return job_.ProcessID() == m_pid;}
private:
	int m_pid;
};


//class handling the history and jobs of the shell
class Shell {
public:
	//singleton method
	static Shell& SingInst() {
		static Shell shell;
		return shell;
	}

public: //API
	bool AddJob(const char* name, int pid, time_t start_time){
		//can't append more jobs if we've reached the maximum supported process count
		if (jobs.size() == MAX_NUM_JOBS) return false;

		//if trying to append a new process with the same pid, return false (and do not append a new job)
		vector<job>::iterator job_it = find_if(jobs.begin(), jobs.end(), JobCmpFn(pid));
		if(jobs.end() != job_it) return false;
		//else
		//add a job to the jobs container
		jobs.push_back(job(++proc_counter, name, pid, start_time));
		return true;
	}
	void AddHistory(string cmdString){
		//if the history queue is full, pop the back, then add the job to the history register
		if (history.size() == MAX_HISTORY_LENGTH) {
			history.pop_back();
		}
		history.push_front(cmdString);
	}
	void PrintJobs() const {
		for (unsigned i = 0; i < jobs.size(); ++i) {
			const job& job__ = jobs.at(i);
			//printf("[%d] %s : %d %lu secs/n", job__.SerialNum(), &job__.Name()[0], job__.ProcessID(), job__.StartTime());
			cout << "[" << job__.SerialNum() <<  "] " << job__.Name() << " " << job__.ProcessID() << " " << job__.StartTime() << " secs" << endl;
		}
	}
	void PrintHistory() const{
		for (unsigned i = 0; i < history.size(); ++i)
			cout << history.at(i) << endl;
	}
	//TODO: implement this one
	void TerminateAll(){

	}
private:
	Shell(){
		jobs.reserve(MAX_NUM_JOBS);

	}

private:
	vector<job> jobs;
	deque<string> history;
	static unsigned proc_counter;
};

unsigned Shell::proc_counter = 0;
//**************************************************Our Classes*********************************************************************

=======
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
//********************************************
// function name: ExeCmd
// Description: interperts and executes built-in commands
// Parameters: pointer to jobs, command string
// Returns: 0 - success,1 - failure
//**************************************************************************************
<<<<<<< HEAD
int ExeCmd(char* lineSize, char* cmdString)
{
	Shell& shl = Shell::SingInst();
	char* cmd; 
	char* args[MAX_ARG];
	char pwd[MAX_LINE_SIZE];
	const char* delimiters = " \t\n";
=======
int ExeCmd(void* jobs, char* lineSize, char* cmdString)
{
	char* cmd; 
	char* args[MAX_ARG];
	char pwd[MAX_LINE_SIZE];
	char* delimiters = " \t\n";  
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
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
<<<<<<< HEAD
			illegal_cmd = true;
		}
		else
		{
			if  (!strcmp(args[1], "-")) //like cd.. - change to "father" working directory (if it exist) and print it.
			{
				if (!strcmp(father_wd, "/0"))//there is no "father" working directory
				{
					illegal_cmd = true;
=======
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
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
				}
				else
				{
					chdir(father_wd);
					printf("%s\n", father_wd);
<<<<<<< HEAD
					illegal_cmd = false;
=======
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
				}
			}
			else // change to args[1] working directory
			{
				//update "father" working directory to be the current directory before changing directory
				getcwd(pwd, sizeof(pwd));//check what it return in failure and perror
<<<<<<< HEAD
				strcpy(father_wd, pwd);
				chdir(args[1]);//change current directory
				illegal_cmd = false;
=======
				strcpy(father_wd,pwd);
				chdir(args[1]);//change current directory
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
			}
		}
		return 0;
	} 
	
	/*************************************************/
	//Dror
	else if (!strcmp(cmd, "pwd")) 
	{
<<<<<<< HEAD
		illegal_cmd = (num_arg != 0);
		if (!illegal_cmd){
			getcwd(pwd, sizeof(pwd));//check what it return in failure and perror
			printf("%s\n", pwd);
=======
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
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
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
<<<<<<< HEAD
		illegal_cmd = (num_arg != 0);
		if (!illegal_cmd)
			shl.PrintJobs();
=======
 		// wait for Dror - idea - let's hold a list (or vector) of struct/class of jobs (we need to think on the fields- Serial_num,name,PID,start_time,...)
		//in this function we just need to print the list.
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	}
	//dror
	/*************************************************/
	else if (!strcmp(cmd, "showpid")) 
	{
<<<<<<< HEAD
		illegal_cmd = (num_arg != 0);
		if (!illegal_cmd)
			printf("smash pid is %d\n",getpid());//check what happens if getpid() failed

=======
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
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	}
	/*************************************************/
	else if (!strcmp(cmd, "fg")) 
	{
		
	} 
	/*************************************************/
	else if (!strcmp(cmd, "bg")) 
	{
<<<<<<< HEAD
  		BgCmd(cmdString, (void*)&shl);
	}
	/*************************************************/
	else if (!strcmp(cmd, "history")) {
		illegal_cmd = (num_arg != 0);
		if (!illegal_cmd)
			shl.PrintHistory();
=======
  		
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	}
	/*************************************************/
	else if (!strcmp(cmd, "quit"))
	{
<<<<<<< HEAD
		illegal_cmd = (num_arg != 0);
		if (!illegal_cmd)
			shl.TerminateAll();
=======
   		
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	} 
	/*************************************************/
	else // external command
	{
 		ExeExternal(args, cmdString);
	 	return 0;
	}
<<<<<<< HEAD
	if (illegal_cmd == true){
		fprintf(stderr, "smash error: > \"%s\"\n", cmdString);
		return 1;
	}
	else{
		shl.AddHistory(cmdString);
		return 0;
	}


=======
	if (illegal_cmd == true)
	{
		printf("smash error: > \"%s\"\n", cmdString);
		return 1;
	}
    return 0;
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
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
<<<<<<< HEAD
	Shell& shl = *((Shell*)jobs);
	char* Command = NULL;
	const char* delimiters = " \t\n";
=======

	char* Command;
	char* delimiters = " \t\n";
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	char *args[MAX_ARG];
	if (lineSize[strlen(lineSize)-2] == '&')
	{
		lineSize[strlen(lineSize)-2] = '\0';
		// Add your code here (execute a in the background)
<<<<<<< HEAD
		int pid = 0;


		/* 
		your code
		*/
		shl.AddJob(lineSize, pid, time(NULL));
=======
					
		/* 
		your code
		*/
		
>>>>>>> 5f6bdba4479b07cd4bc8cfc7d3349500bcc0d351
	}
	return -1;
}

