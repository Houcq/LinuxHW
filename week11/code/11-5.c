#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void pr_exit(int status,pid_t pid)
{
	int sig;
	if(WIFEXITED(status))
		printf("Process %d normal termination,exit status = %d\n,pid,WEXITSTATUS(status)");
	else if (WIFSIGNALED(status)){
		sig = WTERMSIC(status);
		printf("process %d abnormal termination,signal number =%d %s :\n",pid,sig,
		#ifdef WCOREDUMP
			WCOREDUMP(status)?"(core file generated)":"");
		#else
			"");
		#endif
			psignal(sig,"");	
	}
	else if(WIFSTOPPED(status))
	{
		sig = WSTOPSIG(status);
		printf("process %d stop ,signal number = %d:\n",pid,sig);
		psignal(sig,"");
	}
}
int zero = 0;
int main()
{
	pid_t pid;
	int status;
	if((pid = fork()) == 0)
}
