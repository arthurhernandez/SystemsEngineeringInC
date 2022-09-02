#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  int pid; 
  int mypipefd[2];
  int ret;
  char *argument;
  char count = 30;
  
  if (argc != 2) {
    //printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  ret = pipe(mypipefd);
 
  if(ret == -1){
    exit(EXIT_FAILURE);
  }

  pid = fork();
 
  if(pid == -1){
    exit(EXIT_FAILURE);

  }else if(pid > 0){  
//parent process
    argument = argv[1];
    write(mypipefd[1],argument, count);
    close(mypipefd[1]);  

  }else if(pid ==0){
//child process
    char readArg[count];
    read(mypipefd[0], readArg, count);
    printf("%s\n",readArg);  
    close(mypipefd[2]);
  }




exit(EXIT_SUCCESS);
}
