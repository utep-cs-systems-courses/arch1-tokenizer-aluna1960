#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if(c != ' '){
    return 1;
  }
  
  else{
    return 0;
  }
}

char *word_start(char *str){
  
  while(1){
    if (non_space_char(*str)==1 && space_char(*str)==0){
      str = str+1;
    }
    else if(*str=='\0'){
      return 0;
    }
    else{
      return str;
    }
  }
    
}

       
char *word_terminator(char *word){
    
  int i;
  int count = 0;

  if(word_start(word)==0){
    word = 0;
  }
    /*for(i = 0; *(word+i) != ' ' || *(word+i)!='\0';i++){
    word = 0;
  }  
  for(i = 0;*(word+i)!='\0';i++){
    count++;
    }*/
  /*for(i = 0; i<count;i++){
    if(*(word+i)=='\0' || word+i == NULL){
      return NULL;
    }
    }*/
  return word;
}

int count_words(char *str){
  int counter = 0;
  int i=0;
  printf("i");

  while(1){
    if(non_space_char((char)*str)==0){
      printf("%d",non_space_char((char)*str));
      str++;
      printf("i");
      i++;
    }
    if(non_space_char((char)*str)==1){
      str = word_start(str);
      counter++;
      printf("wassup");
    }
    if(*str=='\0'){
      return counter;
     
    }
  }
  return counter;
  /*
  while(1){
    if(*(word_start(str))!='\0'){
      str = word_start(str);
      counter++;
    }
    else{
      return counter;
    }
  }
      /*for(i=0; *(str+i)!='\n' || *(str+i)!='\0' || str+i!=NULL;i++){
	counter++;*/
  //printf("hello");
  //return counter;
}

char *copy_str(char *inStr, short len){
  int i;
  int count = 0;
  for(i = 0; *(inStr+i)!=' ' || *(inStr+i)!='\0';i++){
    count++;
  }
  

  char *newStr=malloc((len+1)*sizeof(char));

  

  for(i = 0; i<len;i++){
    *(newStr+i) = *(inStr+i);
  }
  
  return newStr;
}

char **tokenize(char* str){
  int i = 0;
 
  int count = 0;

  for(i = 0; str+i!= NULL || *(str+i)!='\0';i++){
    count++;
  }
    
  printf("this is the number of words: %d)",count);
  
  char **tokenizer=malloc((count+1)*sizeof(char*));
  
  for(i = 0; i < count;i++){
    
    *(tokenizer+i) = str;
    str = word_start(str);

    }
  for(i=0;i<count;i++){
    printf("%c",**tokenizer+i);
  }
  return 0;
}


void print_tokens(char **tokens){
  int i = 0;
  int k = 1;
  
  while(k){
    if(tokens[i]!=NULL){
      

      printf("%c",*tokens[i]);
    }
    else{
      k = 0;
    }
  }
}

void free_tokens(char **tokens){
  int i;
  int count = 0;
  for(i = 0; (tokens+i)!=NULL;i++){
    free(*(tokens+i));
    count++;
  }

  for(i = count;i>-1;i--){
    free(tokens+i);
  }
  
}
  


  
