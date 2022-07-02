//Submitted by: 311382360 Eran Levi _ 315524389 Or Mendel



#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int global = 0;
void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum)
	{
		case SIGCHLD:
			printf("I am in sighandler : 2\n");
			fflush(stdout);
			raise(SIGUSR1);
			break;
		case SIGUSR1: 
			printf("I am in sighandler : 3\n");
			fflush(stdout);
			k=i/j;
			break;
		case SIGFPE:
			printf("I am in sighandler : 4\n");
			fflush(stdout);
			int *p = NULL;
			*p = 45;
			
		case SIGSEGV:
		    printf("I am in sighandler : 5\n");
		    fflush(stdout);
		    exit(1);
    }
}
void sig_handler2(int signum)
{
    global = 1;
}

int main()
{
	int status;
    signal(SIGINT, sig_handler2);
    
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
	signal (SIGSEGV, sig_handler);

    raise(SIGINT);
	printf("Changed global variable to %d\n",global);
	if (!(fork())) {
		exit(1);
	}
	wait(&status);
    

}