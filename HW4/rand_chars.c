#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include<time.h>


char *lower = "abcdefghijklmnopqrstuvwxyz";
char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void* randLowerChar(){
  int i;
  for(i = 0;i < 10; i++){
    char lowerChar = lower[rand() % 26];
    printf("%c\n",lowerChar);
  }
  return NULL;
}

void* randUpperChar(){
  int x;
  for(x = 0; x < 10; x++){
    char upperChar = upper[rand() % 26];
    printf("%c\n",upperChar);
  }
  return NULL;
}


int main (int argc, char *argv[]) {
  srand(time(NULL));
  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  if(strcmp(argv[1],"-l") == 0){
    randLowerChar();
  }
  else if(strcmp(argv[1],"-u") == 0){
    randUpperChar();
  }
  else{
    exit(EXIT_FAILURE);
  }
exit(EXIT_SUCCESS);
}
