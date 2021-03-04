#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history(){
  List *hist = malloc(sizeof(List));
  Item *histRoot = malloc(sizeof(Item));
  hist->root = histRoot;
  return hist;
}

void add_history(List *list, char *str){
  Item *node=list->root;
  int gid = 1;
  
  for(int i = 0; node->next!=NULL; i++){
    gid++;
    node = node->next;
    
  }
  node->id=gid;
  node->str=str;
  node->next=malloc(sizeof(Item));
}


char *get_history(List *list, int id){
  Item *node = list->root;
  while(node->next!=NULL){
    if(node->id == id){
      return node->str;
    }
    node = node->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *node = list->root;
  while(node->next!=NULL){
    printf("%s\n ",node->str);
    node = node->next;
  }
}

void free_history(List *list){
  Item *node = list->root;

  while(list->root!=NULL){
    if(node->next==NULL){
      free(node);
      node = list->root;
    }
    else{
      node = node->next;
    }
    
  }
  /*while(node->next!=NULL){
    free(node);
    node = node->next;
    }*/
  //free(node);
  // free(list);
}
  


