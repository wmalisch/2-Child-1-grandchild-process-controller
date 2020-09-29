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

    int status;
    pid_t x, y, pid, pid2, pid3;

    pid=fork();
    wait(NULL);
    pid=fork();

    if(pid<0){
        printf("fork unsuccessful\n");
    }

    if(pid>0){

    }

    if(pid==0){

    }




    return 0;
}
