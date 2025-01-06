// Program for system calls of UNIX operating system (OPENDIR, READDIR, CLOSEDIR)

// ALGORITHM:
/*
    1. Start the program
    2. Create struct dirent
    3. Declare the variable buff and pointer dptr
    4. Get the directory name
    5. Open the directory
    6. Read the contents in direcory and print it.
    7. Close the directory
*/
    
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(){
    char dirname[256];
    struct dirent *dptr;
    DIR *dir;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir == NULL){
        perror("Error opening directory");
        return 1;
    }

    while((dptr = readdir(dir)) != NULL){
        printf("%s\n", dptr -> d_name);
    }

    closedir(dir);

    return 0;
}