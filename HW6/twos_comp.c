#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int flipbit = 0;
int digits;

void* sign(int n){
  int total = 0, remainder, i = 1;
  int nTemp = n; 
  while (nTemp != 0){
    remainder = nTemp % 10;
    nTemp = nTemp / 10;
    total += remainder * (i * i);
    ++i;
  }
   
  if(flipbit == 1){
    total = ~total;
    total = (digits * digits) + total;
  }
  if(total > -128 && total < 127){
    signed int sign = (signed int) total;
    printf("%d\n", sign);
  }else{
    exit(EXIT_FAILURE);
  }  
  return NULL;
}

void* unsign(int n){
  int total = 0, remainder, i = 1;
  int nTemp = n;
  while (nTemp) {
    remainder = nTemp % 10;
    nTemp = nTemp / 10;
    total += remainder * i;
    i = i * 2;
  }
  if(total > 0 && total < 256){
    unsigned int unsign = (unsigned int) total;
    printf("%d\n", unsign);
  }else{
    exit(EXIT_FAILURE);
  }
  return NULL;
}

int main (int argc, char *argv[]){

  if (argc != 3) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  
  int n = atoi(argv[1]);
  char *type = argv[2];

  if(strcmp(type,"signed") == 0){
    int temp = n;
    while (temp >= 10){
      temp /= 10; 
    }
    int l = 1;
    temp = n;
    while(temp > 9){
      l++; 
      temp/=10;
      digits = l;
    }
    if(temp == 1){
      flipbit = 1;
    }
    sign(n);  
  }
  else if(strcmp(type,"unsigned") == 0){
    unsign(n); 
  }
  else{
    printf("Error: incorrect integer type\n");
    exit(EXIT_FAILURE);
  }
  
exit(EXIT_SUCCESS);
}

