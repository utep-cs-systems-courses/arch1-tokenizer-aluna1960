#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history(){
  List *hist = malloc(sizeof(List));
  return hist;

}

void add_history(List *list, char *str){
  printf("hello there");
  Item *node=list->root;
  int gid = 1;
  
  for(int i = 0; node->next!=NULL; i++){
    gid+=1;
    node = node->next;
    
  }
  node->next=malloc(sizeof(Item));
  node = node->next;
  node->id=gid;
  node->str=str;
  
}


char *get_history(List *list, int id){
  Item *node = list->root;
  while(node->next!=NULL){
    if(node->id == id){
      break;
    }
    node = node->next;
  }
  return node->str;
}

void print_history(List *list){
  Item *node = list->root;
  while(node->next!=NULL){
    printf("%s",*(node->str));
    node = node->next;
  }
}

void free_history(List *list){
  Item *node = list->root;
  
  while(node->next!=NULL){
    free(node);
    node = node->next;
  }
  free(node);
  free(list);
}
  


