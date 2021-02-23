#include <stdio.h>

#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' '){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if (c == ' '|| c == '\0'){
    return 0;
  }  
  else{
    return 1;
  }
}

char *word_start(char *str){
  
  while(1){
    if(*str = '\0'){
      return str;
    }
    
    if (*(str)==' ' && *(str+1) !=' '){
      return str+1;
    }
    else{
      str++;
    }
  }    
}

       
char *word_terminator(char *word){
    
  int i;
  int count = 0;
  while(*word!='\0'){
    
    if(*word == ' '){
      return word;
    }
    else{
      word++;
    }
  }
}

int count_words(char *str){
  int counter = 0;
  printf("counting");
  while(1){
    if(*str != ' '){
      str++;

      printf("counting");
    }
    else{
      str=str+2;
      counter++;
      
    }
    if(*str=='\0'){
      return counter+1;
    }    
  }
  return counter+1;
}

char *copy_str(char *inStr, short len){
  int i;

  char *newStr=malloc((len+1)*sizeof(char*));
  for(i = 0; i<(len+1);i++){
    if(i == len){
      *(newStr+i) = '\0';
    }
    else{
      *(newStr+i) = *(inStr+i);
      
    }
  }
  return newStr;
}

char **tokenize(char* str){
  int i = 0;
  int iter = 0;
  char *hold = str;
  int count = count_words(str);
  char **tokens = malloc((count+1)*sizeof(char*));
  for( ;i <= count;i++){
    if(i==count){
      *(tokens+i)=0;
    }
    for(int j = 0; *(hold)!=' ';j++){
      iter++;
      hold++;
    }
    
    *(tokens+i) = copy_str(str,iter+1);
    str = word_start(str);
  }
  /*
    if(*(hold+1)=='\0'){
      *(tokens+i) = 0;
    }
    else{
      str = hold;
      iter = 0;
      hold=hold+2;
    }
    }*/
  return tokens;
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
  


  
