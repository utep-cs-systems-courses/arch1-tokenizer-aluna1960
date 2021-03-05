#include <stdio.h>

#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  /*checks to see if the current character is a space
    if it is, then we return a 1*/
  if(c == ' ' || c == '\t'|| c == '\n'){
    return 1;
  }
  /*if it is not then we return a 0*/
  else{
    return 0;
  }
}

int non_space_char(char c){
  /*we check to see if the current word is not a space
    if it is a space, or a null then we return 0*/
  if (c == ' '|| c == '\t'||c=='\n'){
    return 0;
  }
  /*if i is not a space, then we return a 1*/
  else{
    return 1;
  }
}

char *word_start(char *str){
  if(sizeof(str)==0){
    return 0;
  }

  for(int i = 0; i<sizeof(str);i++){
    if(non_space_char(str[i]) == 1){
      return &str[i];
    }
  }
  return '\0'; 
    /*If none of these conditions are applicable, then we just move on to the next character in the character list by increasing the pointer by 1
     */   
}
       
char *word_terminator(char *word){
  /*for this method, initially int i was initialized, nd count was initialized and set to 0.*/
  int i=0;
  int count = 0;
  if(sizeof(word)==0){
    return 0;
  }
  /*then afterwards the code enters into a while loop that checks whether the deferenced pointer is the very last character '\0'*/
  while(*word!='\0'){
    
  /*then *word is checked to see if it is a space, and if it is the pointer word is returned*/
    if(space_char(word[i])){
      return &word[i];
    }
    i++;
  }
  return 0;
}

int count_words(char *str){
  /*first we create a variable counter and set it to 0. This will keep count of the words*/
  int counter = 0;
  /*we create a forever while loop*/
  while(1){
  /*we then check if *str is not equal to space, and if it is then we move down the character list by moving the pointer to the next character by increasing the pointer*/
    if(*str != ' '){
      str++;      
    }
    
    else{
      str=str+2;
      counter++;
      
    }
    /*if we reach the end of the string, then we return the counter plus one*/
    if(*str=='\0'){
      return counter+1;
    }    
  }
  return counter+1;
}

char *copy_str(char *inStr, short len){
  int i=0;
  /*we allocate memory for the string, and we set the size to be the length plus 1 and the size of character pointer.*/
  
  char *newStr=(char*)malloc(sizeof(char)*(len+1));

  /*I made a for loop the goes up to length plus one since theres an extra null memory slot when you allocate memory*/

  while(i<len){
    newStr[i]=inStr[i];
    i++;
  }
  newStr[len]='\0';
  return newStr;
}

char **tokenize(char* str){
  //creating variablies to be utilized, also getting the number of words in the input
  int i = 0, iter = 0, count = count_words(str);
  char *hold = str;
  //allocating memory to insert words into an array of pointers
  
  char **tokens = (char**)malloc(sizeof(char*)*(count+1));
  //iterating through tokens 
  for( ;i < count;i++){
       
    str = word_start(str);
    int size = word_terminator(str)-str;    
    tokens[i] = copy_str(str,size);    
    str = word_terminator(str);
    
  }
  tokens[i] = NULL;
  /*for(int i = 0; i <count;i++){
    printf("%s $",tokens[i]);
    
    }*/
  //returning tokens
  return tokens;
}

void print_tokens(char **tokens){
  for(int i = 0;tokens[i];i++){
    printf("%s, ",tokens[i]);
  }
}

void free_tokens(char **tokens){
  int i;
  int count = 0;
  
  for(i = 0; tokens[i]!=NULL;i++){
    free(tokens[i]);
    count++;
    printf("%d",count);
  }
  free(tokens);
  
  
}
  


  
