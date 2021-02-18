#include <stdio.h>
#include <stdlib.h>

#include "tokenize.h"

int main(int argc, char* argv[]){
  printf("$ ");
  for(int i = 0; i < argc; i++){
    if(argv[i] != "./arg1"){
      printf("%s ",argv[i]);
    }

  }
  printf("\n");
}
  
