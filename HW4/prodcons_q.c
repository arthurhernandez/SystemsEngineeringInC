
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semRead, semWrite, mutex;
char buffer[5];
int count;

char *lower = "abcdefghijklmnopqrstuvwxyz";
char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void* randLowerChar(void* arg){
  int* id = (int*) arg;
  int i;
  for(i = 0;i < 5; i++){
    sem_wait(&semWrite);
    sem_wait(&mutex);
    char lowerChar = lower[rand() % 26];
    buffer[count] = lowerChar;
    count++;
    printf("writer ID: %d, char written: %c\n",*id, lowerChar);
    sem_post(&mutex);
    sem_post(&semRead);
  }
  return NULL;
}

void* randUpperChar(void* arg){
  int* id = (int*) arg;
  int x;
  for(x = 0; x < 5; x++){
    char upperChar = upper[rand() % 26];
    sem_wait(&semWrite);
    sem_wait(&mutex);
    buffer[count] = upperChar;
    count++;
    printf("writer ID: %d, char written: %c\n",*id, upperChar);
    sem_post(&mutex);
    sem_post(&semRead);
  }
  sem_post(&mutex);
  return NULL;
}

void* reader(void* arg){
  int* id = (int*) arg;
  int l;
  int val;
  for(l = 0; l < 5; l++){
    sem_wait(&semRead);
    sem_wait(&mutex);
    char charecter = buffer[count-1];
    count--;
    printf("reader ID: %d, char read: %c\n", *id,charecter);
    sem_post(&mutex);
    sem_post(&semWrite);
  }
  sem_post(&mutex);
  return NULL;
}

int main (int argc, char *argv[]) {
  sem_init(&semWrite, 0, 5);
  sem_init(&semRead, 0, 0);
  sem_init(&mutex, 0, 1);

  if (argc != 1) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  pthread_t tid[8];
  int id[4] = {0,1,2,3};
  count = 0;

  pthread_create(&tid[0], NULL, randLowerChar, (void*) &id[0]);
  pthread_create(&tid[1], NULL, randLowerChar, (void*) &id[1]);
  pthread_create(&tid[2], NULL, randUpperChar, (void*) &id[2]);
  pthread_create(&tid[3], NULL, randUpperChar, (void*) &id[3]);
  pthread_create(&tid[4], NULL, reader, (void*) &id[0]);
  pthread_create(&tid[5], NULL, reader, (void*) &id[1]);
  pthread_create(&tid[6], NULL, reader, (void*) &id[2]);
  pthread_create(&tid[7], NULL, reader, (void*) &id[3]);
  
  int i;  
  for (i = 0; i < 8; i++) {
    pthread_join(tid[i], NULL);
  }
 
  sem_destroy(&semWrite); 
  sem_destroy(&semRead); 

exit(EXIT_SUCCESS);
}
