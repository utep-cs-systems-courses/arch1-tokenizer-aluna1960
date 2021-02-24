#include <stdio.h>

#include <stdlib.h>
#include "tokenizey r.h"

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
    if(*(str+1) == '\0'){
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
  
  while(1){
    if(*str != ' '){
      str++;

      
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
  //creating variablies to be utilized, also getting the number of words in the input
  int i = 0, iter = 0, count = count_words(str);
  char *hold = str;
  //allocating memory to insert words into an array of pointers
  char **tokens = malloc((count+1)*sizeof(char*));

  //iterating through tokens 
  for( ;i <= count;i++){
    if(i==count){
      *(tokens+i)=0;
      break;
    }
    //finding length of each word
    for(int j = 0; *(hold)!=' ';j++){
      iter++;
      hold++;
    }
    //inserting words into tokens
    *(tokens+i) = copy_str(str,iter);
    str = word_start(str);
    iter++;
  }
  //returning tokens
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0, j = 0;
  while(1){
    if(*(tokens)==0){
      break;
    }
    while(*(*(tokens)+j)!='\0'||*(*(tokens)+j)==' '){
      printf("%c",*(*(tokens)+j));
      j++;
    }
    if(*(tokens+1)!=0){
      printf(", ");
    }
    i++;
    tokens = tokens+1;
    j=0;
  }
  tokens=tokens-i;
  return;
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
  


  
