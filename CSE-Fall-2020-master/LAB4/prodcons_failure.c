#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h>
#include<time.h>

int globalVar;

void* randNums(void *n){
  int* intp = (int*) n;
  int i;
    for (i = 0; i < *intp; i++) { 
        int num = (rand() % *intp);
        globalVar = num;
        printf("writer wrote: %d\n", num); 
    }
  return NULL; 
}

int main (int argc, char *argv[]) {
pthread_t tid;

  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  int n =  atoi(argv[1]);

  pthread_create(&tid, NULL, randNums , (void*) &n);
  int x;
  for(x = 0; x < n; x++){
  int num = globalVar;
  printf("main read: %d\n", num);
  }
exit(EXIT_SUCCESS);
}
