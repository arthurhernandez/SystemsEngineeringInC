#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
//init vars
  FILE *textOne;
  FILE *textTwo;
  char *substringOne;
  char *substringTwo;
  int countOne = 0;
  int countTwo = 0;
//init for getline
  char *linePtrOne = NULL;
  size_t lenOfLineOne = 0;
  ssize_t lineOne;
  char *retOne;

  char *linePtrTwo = NULL;
  size_t lenOfLineTwo = 0;
  ssize_t lineTwo;
  char *retTwo;



//check for args
  if (argc != 5) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }
//set vars open files
  textOne = fopen(argv[1], "r");
  substringOne = argv[2];
  textTwo = fopen(argv[3], "r");
  substringTwo = argv[4];

//make sure files are readable
  if ((textOne == NULL) || (textTwo == NULL)) {
      printf("Error: cannot read one or more files");
      exit(EXIT_FAILURE);  
  }


  while ((lineOne = getline( &linePtrOne, &lenOfLineOne, textOne)) != -1) {
  	retOne = linePtrOne;
	while(retOne = strstr(retOne,substringOne)){
	     retOne++;
	     countOne++;
	}
        retOne = NULL;
  }

  while ((lineTwo = getline( &linePtrTwo, &lenOfLineTwo, textTwo)) != -1) {
        retTwo = linePtrTwo;
        while(retTwo = strstr(retTwo,substringTwo)){
             retTwo ++;
             countTwo++;
        }
        retTwo = NULL;
  }


//printData

  printf("File One : %s \n", argv[1]);
  printf("Substring One: %s \n", argv[2]);
  printf("count: %d \n", countOne);

  printf("File Two: %s \n", argv[3]);
  printf("Substring Two: %s \n", argv[4]);
  printf("count: %d \n", countTwo);

  fclose(textOne);
  fclose(textTwo);

exit(EXIT_SUCCESS);
}
