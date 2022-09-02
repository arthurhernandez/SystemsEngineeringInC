#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  int mypipefd[2];
  char *argumentOne;
  char *argumentTwo;
  int count = 30;
 
  if (argc != 3) {
    printf("Error: incorrect number of arguments\n");
    exit(EXIT_FAILURE);
  }

  pipe(mypipefd);
  argumentOne = argv[1];
  argumentTwo = argv[2];
 
    write(mypipefd[1],argumentOne, count);
    write(mypipefd[1],argumentTwo, count);  

    char argOneRead[count];
    char argTwoRead[count];


    read(mypipefd[0], argOneRead, count);
    read(mypipefd[0], argTwoRead, count);

    printf("%s\n",argOneRead); 
    printf("%s\n",argTwoRead); 

    close(mypipefd[0]);
    close(mypipefd[1]);

exit(EXIT_SUCCESS);
}

