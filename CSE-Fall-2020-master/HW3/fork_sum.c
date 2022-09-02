#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> 

#ifndef ASIZE
 #define ASIZE
#endif

int main (int argc, char *argv[]) {
  int array[ASIZE];
  int pid;
  int mypipefd[2];
  int ret;
  long sumParent = 0;
  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  int i;
  for ( i = 0; i < ASIZE; i++) {
    array[i] = i*atoi(argv[1]);
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
    close(mypipefd[0]);
    int j;

    for( j = 0; j < ASIZE/2; j++) {
      sumParent += array[j]; 
    }

    write(mypipefd[1], &sumParent, sizeof(sumParent));
    //printf("Sum of parent process: %lu\n",sumParent);
    close(mypipefd[1]);

 }else if(pid ==0){

//child process
    close(mypipefd[1]);
    long sumChild = 0; 
    int k;
    write(mypipefd[1], array, sizeof(array));
    for ( k = ASIZE/2; k < ASIZE; k++) {
      sumChild += array[k];
    }
 
    read(mypipefd[0], &sumParent, sizeof(sumParent));
    long sum = sumParent + sumChild;
    printf("%lu\n", sum);
    close(mypipefd[1]);        
  }

exit(EXIT_SUCCESS);    
}
