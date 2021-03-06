#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
	/************************************************** command line arguments ***********************************************
		For the purposes of this explanation, assume that "external_program.out" is located in /home/usr/A1/external_program.out 

		When you are testing your program, replace "/home/usr/A1/external_program.out" with the path to the executable file 
		generated when you compile "external_program.c"
		
		To compile assignment1.c: gcc assignment1.c -o assignment1
		To run your program: ./assignment1 /home/usr/A1/external_program.out
		argv[0] = "./assignment1"
		argv[1] = "/home/usr/A1/external_program.out"

		Number of arguments (argc) = 2

		In this assignment, the path to the external program is in argv[1]
	*************************************************************************************************************************/

	// If the path of external_program.out isn't provided by the user, the program will terminate
	if (argc != 2)
	{
		printf("Invalid arguments\n");
		exit(0);
	}

	// Declare variables about to be used
    int status;
    pid_t x, y, pid1,pid2, pid3;

    // Fork to create first child
    pid1=fork();

    // Parent process
    if(pid1>0){
        // Wait until child processes are done (child 1 and 1.1)
        wait(NULL);
        x=getpid();

        // Create child 2
        pid3=fork();

        if(pid3>0){
            x=getpid();
            printf("parent (PID %d) created child_2 (PID %d)\n",x,pid3);
            wait(NULL);

        }
        if(pid3==0){
            x=getpid();
            char buff[20];
            snprintf(buff,19,"%d",x);
            printf("child_2 (PID %d) is calling an external program external_program.out and leaving child_2...\n",x);
            status = execl("external_program.out",buff,NULL);
        }
        // Error control
        if(pid3<0){
            printf("fork unsuccessful\n");
        }

    }

    // First child (child_1)
    if(pid1==0){
        y=getppid();
        x=getpid();
        printf("parent process (PID %d) created child_1 (PID %d)\n",y,x);
        printf("parent (PID %d) is waiting for child_1 (PID %d) to complete before creating child_2\n",y,x);
        // Create child 1.1
        pid2=fork();
        // Child_1
        if(pid2>0){
            // Wait until child_1.1 is done before completing child_1
            wait(NULL);
            printf("child_1 (PID %d) is now complete\n",x);
        }
        // Child_1.1
        if(pid2==0){
            y=getppid();
            x=getpid();
            printf("child_1 (PID %d) created child_1.1 (PID %d)\n",y,x);
        }
        // Error control
        if(pid2<0){
            printf("fork unsuccessful\n");
        }
    }

    if(pid1<0 || pid2<0 || pid3<0){
        printf("fork unsuccessful\n");
    }

    return 0;
}
