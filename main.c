#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

int main(){
  printf("LINKED LIST TESTS\n");
  printf("==================\n");
  struct song_node * p0 = malloc(sizeof(struct song_node)); 
  struct song_node * p1 = malloc(sizeof(struct song_node));
  struct song_node * p2 = malloc(sizeof(struct song_node)); 
  struct song_node * p3 = malloc(sizeof(struct song_node));
  strcpy(p0->artist, "Celine Dion"); strcpy(p0->name, "Because you loved me"); p0->next= p1;
  strcpy(p1->artist, "Celine Dion"); strcpy(p1->name, "My Heart Will Go On"); p1->next= p2;
  strcpy(p2->artist, "Celine Dion"); strcpy(p2->name, "The Power of Love"); p2->next= NULL;
  printf("Testing print_list\n");
  print_list(p0);
}

