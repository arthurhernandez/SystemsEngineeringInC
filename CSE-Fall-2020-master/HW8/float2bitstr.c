
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h> 

int main (int argc, char *argv[]) {
  char sign = '0';
  int decSetting = 0;
  int remSetting = 0;  
  int periodCheck = 0;
  
  if (argc != 2) {
    printf("No input given\n");
    exit(EXIT_FAILURE);
  }
  char *inStr = argv[1];
  char signStr = inStr[0];
    
  if(signStr == '-'){
    sign = '1';
    decSetting = 1;
  }
  
  int i;
  
  for(i = 0; i < strlen(inStr); i++){
    char str = inStr[i];
    if(str == '.'){
       remSetting = i+1;
       periodCheck = 1;
       break;
    }
  }

  if(periodCheck == 0){
    char r[20] = ".0";
    strcat(inStr,r);
    for(i = 0; i < strlen(inStr); i++){
      char str = inStr[i];
      if(str == '.'){
        remSetting = i+1;
        break;
      }
    }
  }

  char decimal[remSetting - decSetting + 1];
  char remainder[strlen(inStr) - remSetting + 1];
  memcpy(decimal, &inStr[decSetting], (remSetting-1) - decSetting );  
  memcpy(remainder, &inStr[remSetting], strlen(inStr) -  remSetting);

  decimal[remSetting - decSetting] = '\0';
  remainder[strlen(inStr) - remSetting] = '\0';
  char rema[20] = "0.";
  strcat(rema,remainder );
  double rem = atof(rema);
                                        // integer
  int num = atoi(decimal);
  int decBin[32];
  i = 0;

  while (num > 0) {
    decBin[i] = num % 2;
    num = num / 2;
    i++;
  }
  
  int ptr = i;
  int e = ptr -1;

  for (i = 0; i < ptr/2; i++){
    int temp = decBin[i];
    decBin[i] = decBin[ptr - 1 - i];
    decBin[ptr - 1 - i] = temp;
  }  
                                          // remainder
  int remBin[25];
  double f;
  int j = 0; 
  double temp;
  while ( j < 25 ) {
    rem = modf(rem, &f);
    temp =  rem * 2;
    remBin[j] = (int) temp;
    rem = temp;
    j++;
  }
  if(remBin[23 - ptr + 1] == 1){
    remBin[23 - ptr] = 1;
  }

                                     //set up matissa

                                    //enter int part after inplicit one 
  int M[23];
  for(i = 0; i < ptr; i++){
    M[i] = decBin[i+1];
  }
                                    //enter frac part
  for(i = 0; i < 23 - ptr + 1; i++){
    M[i + ptr - 1] = remBin[i];
  }
                                   //exp to bin 
  int exp = e + 127; 
  
  int expBin[32];
  i = 0;
  while (exp > 0) {
    expBin[i] = exp % 2;
    exp = exp / 2;
    i++;
  }

  int ptrExp = i;
  for ( i = 0; i < ptrExp/2; i++){
        int temp = expBin[i];
        expBin[i] = expBin[ptrExp - 1 - i];
        expBin[ptrExp - 1 - i] = temp;
  }
 
                           //print
  printf("%c",sign);

  float numberInF = atof(argv[1]);

  if((numberInF < 2.0) && (numberInF > -2.0)){
  printf("0");
  }  

  for(i = 0; i < ptrExp; i++){
    printf("%d", expBin[i] );
  }
  for(i = 0; i < 23; i++){
  printf("%d", M[i]);
  }   
  printf("\n");
exit(EXIT_SUCCESS);
}
