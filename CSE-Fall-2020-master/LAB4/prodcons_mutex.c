
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<time.h>

sem_t r_mutex, w_mutex;
int globalVar;

void* randNums(void *n){
  int* intp = (int*) n;
  int i;
    for (i = 0; i < *intp; i++) {
        sem_wait(&w_mutex);
        int num = (rand() % *intp);
        globalVar = num;
        printf("writer wrote: %d\n", num);
        sem_post(&r_mutex);
    }
  return NULL;
}

int main (int argc, char *argv[]) {
pthread_t tid;
  sem_init(&w_mutex, 0, 1);
  sem_init(&r_mutex, 0, 0);
  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  int n =  atoi(argv[1]);

  pthread_create(&tid, NULL, randNums , (void*) &n);
  int x;
  for(x = 0; x < n; x++){
  sem_wait(&r_mutex);
  int num = globalVar;
  printf("main read: %d\n", num);
  sem_post(&w_mutex);
  }
exit(EXIT_SUCCESS);
}

