#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
  char* line = NULL;
  size_t len = 0;
  int count = 0;
  int numRead = 0;
  char temp = '\0';
  if(argc < 2){
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  for (int i = 1; i < argc ; i++){
    FILE *fp = fopen(argv[i],"r");
    if(fp == NULL){
      printf("wzip: cannot open file\n");
      exit(1);
    }
    while((numRead = getline(&line, &len, fp)) != EOF){
      if(temp == '\0'){
	temp = *line;
      }
      for(int i = 0; i < numRead; i++){
        if(temp == *line){
          count++;
          line++;
        }else{
          fwrite(&count, sizeof(int), 1, stdout);
          fputc(temp, stdout);
          temp = *line;
          count = 1;
	  line++;
        }
      }
      line = NULL;
      len = 0;
    } 
  }fwrite(&count, sizeof(int), 1, stdout);
   fputc(temp, stdout);
  return 0;
}
