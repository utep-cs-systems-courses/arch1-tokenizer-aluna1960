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
  
  scanf("%[^\n]\0",words);
  
  char r = ' ';
  
  char *p = words;
  
  printf("%s\n",words);
  char **tokens = tokenize(p);
  int i = 0;
  int check = 1;
  //printf("First word of token 1: \n");
  /* while(check){
    printf("%c",*(*(tokens)+i));
    i++;
    if(*(*(tokens)+i) == *word_start(p)){
      check = 0;
    }
    }*/
  /*check = 1;
  printf("\n");
  printf("Token 2 word: \n");
  while(check){
    printf("%s",*(*(tokens+1)+i));
    i++;
    if(*(*(tokens+1)+i) == '\0'){
      check = 0;
    }
    }*/  
  //char *str = copy_str(p,5);
  //printf("Second set: %s",*(str));
  printf("this is the first char of token 1: %c\n",*(*(tokens)+1));
  tokens = tokens+1;
  printf("this is the first char of token 2: %c\n",*(*(tokens)));
  //tokens = tokens+1;
  //printf("this is the first char from token 2: %c\n",*(*(tokens)));
  tokens = tokens-1;

  printf("these are the tokens right under this: \n");
  print_tokens(tokens);
  printf("\n");
  printf("Testing space_char: %i\n",space_char(r));
  printf("Testing word_start: %c\n",*(word_start(p)));
  printf("Testing non_space_char: %i\n",non_space_char(r));
  printf("%i\n",count_words(p));
  return 0;
  
}

