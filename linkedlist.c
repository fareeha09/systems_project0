#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

//prints the linked list
void print_list( struct song_node *cur_node){
  printf( "song list: ");
  while( cur_node) {
    printf( "%s: \"%s\" | ", cur_node->artist, cur_node->name);
    cur_node = cur_node->next;
  }
  printf( "\n");
}

//takes an artist and song name and inserts it to the front of the linked list
struct song_node *insert_front(struct song_node *prev_front, char name[100], char artist[100]) {
  struct song_node *new_node = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  new_node->next = prev_front;
  return new_node;
}

//takes an artist and song name and inserts it into the correct place (ordered)
struct song_node *insert_ordered(struct song_node *cur_node, char name[100], char artist[100]) {
  
  struct song_node *new_node = malloc( sizeof( struct song_node));
  struct song_node *before = malloc( sizeof( struct song_node));
  struct song_node *after = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  new_node->next = NULL;
  
  while (cur_node){
	  if (strcmp(new_node, cur_node) < 0){
		before = cur_node;
		cur_node = cur_node->next;
		}
	  else if (strcmp(new_node, cur_node) > 0){
		before->next = new_node;
		new_node->next = cur_node;
		cur_node=NULL;
	    }
	  else {return NULL;}
	  
  return new_node;
}
}


//given an artist and song name and returns a pointer to it.
struct song_node *find_song( char song_name[100], char artist[100], struct song_node *cur_node) {
  char *artistp = artist;
  while (cur_node){
	  if (!strcmp( artistp, cur_node->artist)){
		break;    
	  } cur_node = cur_node->next;
  }
  if (!cur_node) {return NULL;}
  char *songp = song_name;
 
  while(cur_node) {
    if (!strcmp( songp, cur_node->name)){
		return cur_node; } cur_node = cur_node->next;

    } return NULL;
}

//finds an artist and returns a pointer to its first song
struct song_node *first_song( char artist[100], struct song_node *cur_node){
  char *artistp = artist;
  while(cur_node) {
	if(!strcmp( artistp, cur_node->artist)){
		return cur_node;
	} 
	cur_node = cur_node->next;
  }  
    printf( "artist not found\n");
    return NULL;
}

//helper function
int length( struct song_node *node ){
	int counter = 0;
	while (node){ counter++; node = node->next;}
	return counter;
}

//returns a pointer to a random song
struct song_node *random_song(struct song_node *first){
	srand( time(NULL) );
	int size= length(first);
	int num = rand() % size;
	while(num){
		first = first->next;
		num--;
	}
	return first;
}

//takes a pointer to a song and then returns that node
void remove_song( struct song_node *cur_node, struct song_node *removed){
  struct song_node *before = malloc(sizeof(struct song_node));
  while (cur_node){
	  if (strcmp(cur_node, removed)){
		before = cur_node;
		cur_node = cur_node->next;} 
      else {cur_node = NULL;}
  }	
  before->next = removed->next;
  free(removed); 
}

//free the entire list starting from curnode and return a null pointer if all goes as planned
struct song_node * free_list(struct song_node *cur_node) {
    while( cur_node) {
    struct song_node *next_node = cur_node->next;
    free( cur_node);
    cur_node = next_node;
  }
  return cur_node;
}
