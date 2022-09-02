#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int globalInt = 0;

int main (int argc, char *argv[]) {
  int pid;
//check for args

  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  globalInt = atoi(argv[1]);

//printf("global Int is: %d", globalInt);
  pid = fork();
  if(pid == -1){
    exit(EXIT_FAILURE);
  }else if(pid > 0){

//parent process
    printf("Hello World\n");
    globalInt = globalInt + 1; 
    printf("Parent: %d\n",globalInt);
  }else if(pid ==0){

//child process
    printf("Hello World\n");
    globalInt = globalInt - 1;
    printf("Child: %d\n",globalInt);
  }

exit(EXIT_SUCCESS);
}



