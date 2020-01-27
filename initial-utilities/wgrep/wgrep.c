#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[]){
  size_t len;
  char* term = NULL;
  char* fileName = NULL;
  char* line = NULL;
  if (argc >= 2){
    term = argv[1];
    if(argc == 2){
      while(getline(&line, &len, stdin) != EOF){
        if(strstr(line,term) != NULL){
          printf("%s", line);
        }
      }
    }else{
      for(int i = 2; i < argc; i++){
        fileName = argv[i];
        FILE *fp = fopen(fileName,"r");
        if(fp == NULL){
          printf("wgrep: cannot open file\n");
          exit(1);
        }
        while(getline(&line,&len,fp) != EOF)
        {
          if(strstr(line,term) != NULL){
            printf("%s", line);
          }
        }
      }
    }
  }if (argc == 1){
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  return 0;
}
