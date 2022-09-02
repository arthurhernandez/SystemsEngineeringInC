#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> 
#ifndef INCCNT   
 #define INCCNT
#endif

void* append(void *arg);

void* increment(void *arg);

void* voidString;
void* voidNumber;

int main (int argc, char *argv[]) {
//init
  pthread_t tid1, tid2;
  char* substring = argv[1];
  int number = atoi(argv[2]); 
 
  voidString = (void*) substring;
  voidNumber = (void*) &number;

//check for args
  if (argc != 3) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
//create threads
  pthread_create(&tid1, NULL, append, (void*) &voidString);
  pthread_create(&tid2, NULL, increment, (void*) &voidNumber );
  
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

exit(EXIT_SUCCESS);
}


void* append (void *arg){
  char example[10] = " Example\n";
  char* argSubstring = (char*) voidString;
  strcat(argSubstring, example);
  printf("String: %s",argSubstring);  
 
  return NULL;
}

void* increment(void *arg){
  int* number = (int*) voidNumber;
  int incrementedAmount = *number + INCCNT;
  printf("Count: %d\n", incrementedAmount);

  return NULL;    
}
