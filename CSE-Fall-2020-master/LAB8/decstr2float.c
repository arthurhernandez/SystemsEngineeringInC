
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main (int argc, char *argv[]) {
  int sign;
  int exponent;
  float mantissa;
  float number;
  int exp;
  if (argc != 2) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  char* input = argv[1];
  
  if(strlen(input) != 32){
    printf("Incorrect input argument\n");
    exit(EXIT_FAILURE);
  }

  int i; 
  for(i = 0; i < 32; i++){
    char sym = input[i];
    if(sym != '1' && sym != '0'){
      printf("Incorrect input argument\n");
      exit(EXIT_FAILURE);
    }
  }

  int n = 0;
  for(i = 8; i > 0; i--){
    char in = input[i];
    if(in == '1'){
      exponent += pow(2,n) * 1;
    }
    n++;
  }  
  
  int count = -1;
  for(i = 9; i < 32;i++){
    char db = input[i];
    if(db == '1'){
      mantissa += pow(2,count) * 1;
    } 
    count--;
  }
  sign = input[0];
  if(exponent == 0 || exponent == 255){
    exp = 1 - 127;
  }else{
    exp = exponent - 127;
  }
 
  if(exponent != 0 && exponent != 255){
    mantissa += 1; 
  }
   
  number = pow(-1,sign)  * (mantissa * pow(2, exp));
 
  printf("Sign: %c\n",input[0]);
  printf("Exponent: %d\n",exponent);
  printf("Mantissa: %.17g\n",mantissa);
  printf("Number: %.7g\n",number);
exit(EXIT_SUCCESS);
}
