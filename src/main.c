#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"


int main(){

  printf("Hello, welcome to my program! ");

  /*variables to be used*/
  char words[30];
  
    /*checking the users well being while also getting the sentence to tokenize */
  printf("Lets get started! Please enter a sentence of your choosing: \n\n");
  /*for(int i = 0; *(w+i)!='\0';i++){
    printf("%c",*(w+i));
    }*/
  scanf("%[^\n]\0",words);
  //printf("%s\n",words);
  char r = ' ';
  char *p = words;
  /*sentence*/
  /*while(fgets(words,30,stdin)){
    char *pointer = words;
    printf("hello\n");
    printf("%c\n",words[0]);
    printf("%c\n",*pointer);
    
    printf("this is count: %i\n",count_words(pointer));
    printf("what");
    exit(0);
    }*/
  printf("%i\n",non_space_char(r));
  return 0;
  
}

