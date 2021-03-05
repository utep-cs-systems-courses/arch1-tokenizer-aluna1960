#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  List *histList = init_history();
  char answer[1];
  char choice[1];
  char q[20]; 
  char **tokens;
  char wordsHolder[20] = "k";
  //printf("To tokenize press 't'; to make Linked list press 'l':\n");
  //scanf(" %[^\n]\0",&choice);
  printf("We will now proceed to make a history of what you want to enter.\n");
  //if(choice[0] == 'l'){
  while(wordsHolder[0]!='n'){
   
    int count = 0;
    printf("Enter a word/sentence please: \n");
    
    scanf(" %[^\n]\0",wordsHolder);
    for(int i = 0; wordsHolder[i]!='\0';i++){
      count++;
    }
    add_history(histList,copy_str(wordsHolder,count));
    printf("Would you like to add more words? y/n: ");

    scanf(" %[^\n]\0",wordsHolder);
    /*if(wordsHolder[0] == 'n'){
      print_history(histList);
      printf("which of the sentences do you want to print out? enter an ID: \n");
       
      }*/
  }
  while(1){
    char choice2[25];
    char choice3[25];
    printf("To view history- !ID \tTokenize an element from history- 't' \tQuit- 'q'");
    scanf(" %[^\n]\0", choice2);
    char *ptr1;
    
    long num2;
    long num = strtol(&choice2[1],&ptr1,10);
    if(choice2[0]=='!'){
      
      printf("Item associated with %s: %s\n",&choice2[1], get_history(histList,(int)num));
    }
    if(choice2[0]=='t'){
      
      printf("which would you like to tokenize? Enter ID :\n");
      scanf(" %[^\n]\0",choice3);
      num2 = strtol(&choice3[0],&ptr1,10);
      //      char *pointer=get_history(histList,(int)num2);
      tokens=tokenize(get_history(histList,(int)num2));
      print_tokens(tokens);
      free_tokens(tokens);
      printf("\nWould you like to view another history element or Tokenize another sentence? y/n\n");
      scanf("%[^\n]\0",answer);
      if(answer[0]=='n'){
	break;
      }
    }
    if(choice2[0]=='q'){
      break;
    }
    
  }
    
  /*else{

    char tokenStr[75];
    
    printf("Enter the sentence you want tokenized: \n");
    scanf(" %[^\n]\0",tokenStr);
    char *follow=tokenStr;
    char **tokenizeStr = tokenize(follow);
    print_tokens(tokenizeStr);
    printf("\nthese is your sentence tokenized \n");
    printf("We will now free the space in your newly created tokenized sentence\n\n");
    free_tokens(tokenizeStr);
    printf("This is now your current tokenized string:\n\n");
    print_tokens(tokenizeStr);
    
    }*/  
    
  //print_history(histList);
  //printf("\n\n");

  /*char *tokePointer;
  char tokeWords[25];
  
  
  printf("Enter the sentence you would like to tokenize: \n");
  scanf(" %[^\n]\0",tokeWords);
  tokePointer = tokeWords;
  char **tokes = tokenize(tokePointer);
  
  
  print_tokens(tokes);*/
  //printf("Hello, welcome to my program! ");
  
  /*variables to be used*/
  //char words[300];
  
  /*checking the users well being while also getting the sentence to tokenize */
  /*printf("Lets get started! Please enter a sentence of your choosing: \n\n");
  
  scanf(" %[^\n]\0",words);
  
  char r = 'a';
  
  char *p = words;
  
  printf("%s\n",words);
  char **tokens = tokenize(p);
  int i = 0;
  int check = 1;
  printf("aye\n");
  */

  
  //printf("this is the first char of token 1: %c\n",*(*(tokens)+1));
  //tokens = tokens+1;
  //printf("this is the first char of token 2: %c\n",*(*(tokens)));
  //tokens = tokens+1;
  //printf("this is the first char from token 2: %c\n",*(*(tokens)));
  //tokens = tokens-1;

  /*printf("these are the tokens right under this: \n");
  print_tokens(tokens);
  printf("\n");
  printf("Testing space_char: %i\n",space_char(r));
  printf("Testing word_terminator: %c\n",*(word_terminator(p)));
  printf("Testing word_start: %c\n",*(word_start(p)));
  printf("Testing non_space_char: %i\n",non_space_char(r));
  printf("%i\n",count_words(p));
  printf("this is the copy: %s",copy_str(p,sizeof(p)));
  free_tokens(tokens);
  print_tokens(tokens);
  printf("\n");
  //-----------------------------Linked Lists------------------------------------
  List *pract = init_history();
  
  add_history(pract,"sup");
  
  add_history(pract,"supskie");
  
  add_history(pract,"suppers");
  printf("this is first one: %s\n",get_history(pract,1));
  print_history(pract);
  printf("5th one: %s\n",get_history(pract,2));
  printf("6th one: %s\n",get_history(pract,3));*/
  //free_history(pract);*/
  return 0;
  
}

