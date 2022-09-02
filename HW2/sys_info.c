#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
//init
//  pid_t pid;
  int pid;
  int mypipefd[2];
  char *torf;
  int ret;
  char bin[50] = "/bin/";
  char *binaryName;
  char *exicutible;

//check conditions
  if (argc != 3) {
   // printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  binaryName = argv[1];
  exicutible = argv[2]; 
  ret = pipe(mypipefd);

   if(ret == -1){
   // printf("Error in pipe\n");
    exit(EXIT_FAILURE);
  }

//fork 1 for write 2 for read in mypipefd

  pid = fork();
  if(pid == -1){
    exit(EXIT_FAILURE);
  }
  //parent process
  else if(pid > 0){
    write(mypipefd[1], binaryName, sizeof(binaryName));
    write(mypipefd[1], exicutible, sizeof(exicutible));
    close(mypipefd[1]);
 
  }else if(pid == 0){
  //child process
    close(mypipefd[2]);
    read(mypipefd[0], binaryName, sizeof(binaryName));
    read(mypipefd[0], exicutible, sizeof(exicutible));
    
    if(strstr(binaryName, "/bin/") == NULL){
      strcat(bin,binaryName);
      binaryName = bin;
    }
    execl(binaryName,binaryName,exicutible, NULL);
    exit(EXIT_FAILURE);
    close(mypipefd[1]);
  }


exit(EXIT_SUCCESS);
}
