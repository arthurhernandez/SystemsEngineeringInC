#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
  fprintf(stderr, "%s", "We want this program to fail\n");
  exit(EXIT_FAILURE);
}
    
