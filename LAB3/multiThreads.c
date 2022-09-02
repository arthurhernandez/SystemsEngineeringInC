#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> 
#include <time.h> 

void* readFile(void *arg);

struct input_args {
  FILE *file;
  char *substring;
  };
  
typedef struct input_args IA;


  
int main (int argc, char *argv[]) {
  pthread_t tid1, tid2;
  IA arg1 = {};
  IA arg2 = {};
  double timeSpentMainThread = 0.0;

  if (argc != 5) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  
  arg1.file = fopen(argv[1], "r");
  arg1.substring = argv[2];
  arg2.file = fopen(argv[3], "r");
  arg2.substring = argv[4];
  
  clock_t beginMainThread = clock();
  pthread_create(&tid1, NULL, readFile, (void*) &arg1);
  pthread_create(&tid2, NULL, readFile, (void*) &arg2);  
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL); 
  clock_t endMainThread = clock();

  timeSpentMainThread += (double)(endMainThread - beginMainThread) / CLOCKS_PER_SEC;
  //printf("Time spent in main thread: %lf\n", timeSpentMainThread);

  
  exit(EXIT_SUCCESS);
}

void* readFile(void *arg) {
  clock_t beginThread = clock();
  IA* args = (IA*) arg;
  char *linePtr = NULL;
  size_t lenOfLine = 0;
  ssize_t line;
  char *ret;
  int count = 0;
  double timeSpentThread = 0.0;
  
  if (args->file == NULL) {
    printf("Error: cannot read the file");
    exit(EXIT_FAILURE);
  }

  while ((line = getline( &linePtr, &lenOfLine, args->file)) != -1) {
    ret = linePtr;
    while(ret = strstr(ret,args->substring)){
      ret++;
      count++;
    }
  ret = NULL;
  }
  clock_t endThread = clock();
  timeSpentThread += (double)(endThread - beginThread) / CLOCKS_PER_SEC;
  //printf("timeSpentInThread: %lf", timeSpentThread); 
  printf("substring: %s Count: %d\n",args->substring,count);

  
  return NULL;
}
