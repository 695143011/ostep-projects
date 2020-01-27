#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char * argv[]){
  char *fname = NULL;
  for(int i = 1; i < argc; i++){
    fname = argv[i];
    FILE *fp = fopen(fname,"r");
    char buffer[MAX];
    if(fp == NULL){     
      printf( "wcat: cannot open file\n");
      exit(1);
    }else if(fname == NULL){
      exit(0);
    }
    while(fgets(buffer,MAX,fp) != NULL){
      printf("%s", buffer);
    }
    fclose(fp);
  }
  return 0;
}

