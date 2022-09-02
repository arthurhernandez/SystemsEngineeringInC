#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

char bin[9];
char *binary(int n){
    bin[0] = '\0';
    int i;
    for (i = 128; i > 0; i >>= 1) {

        if( (n & i) == i ){
          strcat(bin, "1");
        }else{
          strcat(bin, "0");
        }
    }
    return bin;
}


int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  
  int n = atoi(argv[1]);
  
  if( (n < -128) || (n > 127) ){
    exit(EXIT_FAILURE);
  }
  
  printf("%s\n", binary(n));  

exit(EXIT_SUCCESS);
}
