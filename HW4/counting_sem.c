#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem; 

void* funtA(void *arg){
  sem_wait(&sem);
  printf("A\n");
  return NULL;
}

void* funtB(void *arg){
  sem_wait(&sem);
  printf("B\n");
  return NULL;
}

void* funtC(void *arg){
  sem_wait(&sem);
  printf("C\n");
  return NULL;
}

int main (int argc, char *argv[]) {
  pthread_t tid[3];

  if (argc != 1) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  //if pshared val is 0 then shared thru threads, if nonzero shared thru processes 
  sem_init(&sem, 0, 2);
  
  pthread_create(&tid[0], NULL, funtA, NULL);
  pthread_create(&tid[1], NULL, funtB, NULL);
  sem_post(&sem); // FIX for code issue
  pthread_create(&tid[2], NULL, funtC, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);

  sem_destroy(&sem); 

exit(EXIT_SUCCESS);
}


