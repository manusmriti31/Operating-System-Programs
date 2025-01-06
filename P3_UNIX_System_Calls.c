// PROGRAM FOR SYSTEM CALLS OF UNIZ OPERATING SYSTEM

/*
    1. Start the program
    2. Declare the variables pid, pid1, pid2
    3. Call fork() system call to create process
    4. if pid == -1, exit
    5. if pid != -1, get the process id using getpid()
    6. Print the process id
    7. Stop the program
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int pid, pid1, pid2;

    pid = fork();
    if (pid == -1){
        printf("Error in process creation\n");
        exit(1);
    }
    if (pid != 0){
        pid1 = getpid();
        printf("The parent  process id is %d\n", pid1);
    }
    else{
        pid2 = getpid();
        printf("The child process ID is %d\n", pid2);
    }

    return 0;

}

// fork() cannot be used in windows and there is no equivalent of it in windows to