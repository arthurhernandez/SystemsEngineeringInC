#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  char bin[50] = "/bin/";
  char *binaryName;
  char *exicutible;

  if (argc != 3) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
  
  binaryName = argv[1];
  exicutible = argv[2]; 
  
  if(strstr(binaryName, "/bin/") == NULL){
      strcat(bin,binaryName);
      binaryName = bin;
  }
  
  execl(binaryName,binaryName,exicutible, NULL);

exit(EXIT_SUCCESS);
}
