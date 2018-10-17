#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

//takes an artist and song name and inserts it to the front of the linked list
struct song_node *insert_front(struct song_node *prev_front, char name[100], char artist[100]) {
  struct song_node *new_node = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  new_node->next = prev_front;
  return new_node;
}

//takes an artist and song name and inserts it into the correct place (ordered)
struct song_node *insert_song_ordered( char name[100], char artist[100], struct song_node *cur_node) {
  struct song_node *new_node = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  char *artist0= artist;
  char *cur_artist= cur_node->artist;
  while (strcmp(artist0, cur_artist) < 0){
    cur_node = cur_node.next;
    cur_artist = cur_node->artist;
  }

  cur_node -= sizeof(struc song_node);
  struct song_node *after = cur_node->next;
  cur_node->next= new_node;
  new_node->next = after;
}

//prints the linked list
void print_list( struct song_node *cur_node) {
  printf( "song list: ");
  while( cur_node) {
    printf( "%s by %s,", cur_node->name, cur_node->artist);
    cur_node = cur_node->next;
  }
  printf( "no next\n");
}

//given an artist and song name and returns a pointer to it.
struct song_node *find_song( char artist[100], char song_name[100], struct song_node *cur_node) {
  char *artistp = artist;
  char *cur_artist= cur_node->artist; //makes char pointer to the artist in the current node
  while( strcmp( artistp, cur_artist)) {
    cur_node = cur_node->next;
    cur_artist = cur_node->artist;
    }
  
  char *songp = song_name;
  char *cur_song = cur_node->name; //makes char pointer to the song in the current node
  while( strcmp( songp, cur_song)) {
    if( strcmp( artistp, cur_song))
      return NULL;
    cur_node = cur_node->next;
    cur_song = cur_node->name;
    }

  return cur_node;
}

//finds an artist and returns a pointer to its first song
struct song_node *first_song( char artist[100], struct song_node *cur_node){
	char *artistp = artist;
	while( strcmp( artistp, cur_node)) {
    cur_node = cur_node->next;
  } 
	return cur_node;
}

//returns a pointer to a random song
struct song_node *random_song(struct song_node *first){
	srand( time(NULL) );
	int size= sizeof(struct song_node);
	int num = rand() % size;
	return ("%p ", first+=num;);
}

//takes a pointer to a song and then returns that node
void remove_song( struct song_node *song){
  struct song_node *pointer = find_song(song);
  struct song_node *before = pointer-sizeof(struct song_node);
  before->next = pointer->next;
  free(song); 
}

//free the entire list starting from curnode and return a null pointer if all goes as planned
struct song_node * free_list(struct song_node *cur_node) {
    while( cur_node) {
    struct node *next_node = cur_node->next;
    free( cur_node);
    cur_node = next_node;
  }
  return cur_node;
}
