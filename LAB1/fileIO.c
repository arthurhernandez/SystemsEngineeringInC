#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
  char *linePtr = NULL;
  size_t lenOfLine = 0;
  ssize_t line;
  char lineChars[100];
  char *substring;
  char *ret;
  int count = 0;
   
  if (argc != 3) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  FILE* text = fopen(argv[1], "r");
  substring = argv[2];

  if (text == NULL) {
      printf("Error: cannot read file");
      exit(EXIT_FAILURE);  
  }

  while ((line = getline( &linePtr, &lenOfLine, text)) != -1) {
  	ret = strstr(linePtr,substring);
  	if(ret != NULL){ count++; }
 	ret = NULL;
  }

//  printf("File: %s \n", argv[1]);
//  printf("Substring: %s \n", argv[2]);
  printf("%d", count);

  fclose(text);
  exit(EXIT_SUCCESS);

}

