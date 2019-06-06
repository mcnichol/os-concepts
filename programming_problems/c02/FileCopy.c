#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *getLine(char *buff, int size, FILE *stream);

int main(int argc, char *argv[]){
  char copyFrom[100];
  char copyTo[100];
  FILE *fCopyFrom;
  FILE *fCopyTo;

  //Acquire input file name
    //Write prompt to screen
    //Accept input
  printf("Enter file to copy: ");
  getLine(copyFrom, sizeof(copyFrom), stdin);
  
  //Acquire output file name
    //Write prompt to screen
    //Accept input
  printf("Enter output file: ");
  getLine(copyTo, sizeof(copyTo), stdin);

  printf("Copying from %s to %s\n", copyFrom, copyTo);

  //Open the input file
    //If file doesn't exist, abort
  if ((fCopyFrom = fopen(copyFrom, "r")) == NULL){
    printf("File %s doesn't exist!\n", copyFrom);
    exit(-1);
  }

  //Create output file
    //If file exists, abort
  if ((fCopyTo = fopen(copyTo, "r")) != NULL){
    printf("File %s exists!\n", copyTo);
    exit(-1);
  }

  fCopyTo = fopen(copyTo, "w");

  char *buffer = NULL;
  size_t len = 0;
  ssize_t read;


  while ((read = getline(&buffer, &len, fCopyFrom)) != -1) {
    fputs(buffer, fCopyTo);
  }

  fclose(fCopyTo);

  printf("File Copy Completed");

  //Loop
    //Read from inputfile
    //Write to output file
  //Until read fails
  //Closee output file

  //Write completion message to screen

  //Terminate normally
  exit(0);
}

char *getLine(char *buff, int size, FILE *stream){

  fgets(buff, size, stream);

  size_t len = strlen(buff);
  if (len > 0 && buff[len-1] == '\n'){
     buff[len-1] = '\0';
    return buff;
  }
  
  return 0;
}
