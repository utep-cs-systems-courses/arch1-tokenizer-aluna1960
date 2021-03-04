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
  /*for word start, we are getting the first character of the next word
    here we start with a while loop that goes on forever. In the first conditional we check if the next character the pointer points to is null, or "\0", then we return the current pointer*/
  
  if(sizeof(str)==0){
    return '\0';
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
    return '\0';
  }
  /*then afterwards the code enters into a while loop that checks whether the deferenced pointer is the very last character '\0'*/
  while(*word!='\0'){
    
  /*then *word is checked to see if it is a space, and if it is the pointer word is returned*/
    if(space_char(word[i])){
      return &word[i];
    }
    i++;
      //word++;
   
  }
  return '\0';
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
    /*if it is equal to a space, then we have to move the pointer up twice, so as to not count the space, and we count each word. Ex: "word1 word2"; we only count if it is not a space that way we count each word.*/
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
  
  
  /*for(i = 0; i<(len+1);i++){*/
  /*if i = length, then we set *(newStr+i) = '\0'*/
  /*if(i == len){
      *(newStr+i) = '\0';
      }*/
    

    /*if not, then *(newStr+i) is equal to the input string pointer*/

    /*else{
      *(newStr+i) = *(inStr+i);
      
    }
    }*/
  /*We return the newly created newStr*/
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
  for(int i = 0;tokens[i]!=NULL;i++){
    printf("%s, ",tokens[i]);
  }
  
  //variables to be utilized
  /*int i = 0, j = 0;
  //iterating through each character of each token
  while(1){
    //checking if we have reached the last token, which should be null
    if(*(tokens)==0){
      //we then exit the while loop
      break;
    }

    //printing out each character of the token were at
    while(*(*(tokens)+j)!='\0'||*(*(tokens)+j)==' '){

      //print each character of the token (word)
      printf("%c",*(*(tokens)+j));
      //j is used to go to the next character in the token were at
      j++;
    }
    //if we reach the end of the token, then we add a parenthesis and go to the next
    if(*(tokens+1)!=0){
      printf(", ");
    }
    //increase the value of i
    i++;
    //go to the next token (word)
    tokens = tokens+1;
    //set j, which was used to traverse through the characters of the word back to 0
    j=0;
  }
  //we return to the first token by subtracting "i", which was the number or times that tokens array was increased.
  tokens=tokens-i;*/
 
}

void free_tokens(char **tokens){
  int i;
  int count = 0;
  
  for(i = 0; (tokens+i)!=NULL;i++){
    free(*(tokens+i));
    count++;
  }

  for(i = count;i>0;i--){
    free(tokens+i);
  }
  free(tokens);
  
}
  


  
