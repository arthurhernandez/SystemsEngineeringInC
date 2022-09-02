#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> 
#include <string.h>
#include <unistd.h>
#ifndef ASIZE 
  #define ASIZE 10
#endif
#ifndef NTHREADS  
  #define NTHREADS 10
#endif

struct input_args {
  int id;
  int array[ASIZE];
};

int sum;
void* summ(void *arg);
typedef struct input_args IA;

int main (int argc, char *argv[]) {
  int array[ASIZE];
  pthread_t tid[NTHREADS];
  int i; 
  for (i = 0; i < ASIZE; i++) {
    array[i] = i*atoi(argv[1]);
  }

  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
 
  IA arg1 = {};  
 
  for (i = 0; i < ASIZE; i++) {
     arg1.array[i] = array[i];
  }
  
  for (i = 0; i < NTHREADS; i++) {
    arg1.id = i ;
    pthread_create(&tid[i], NULL, summ, (void*) &arg1);
  }
 
  for (i = 0; i < NTHREADS; i++) {
    pthread_join(tid[i], NULL);  
  }
  
  printf("%d\n", sum);

exit(EXIT_SUCCESS);
}

void* summ(void *arg) {
  int size = ASIZE / NTHREADS;
  IA* args = (IA*) arg; 
  int pos = args->id * size;
  int i;
  for (i = pos; i < pos + size; i++) {
      sum += args->array[i];      
  }
  
  return NULL;
}
