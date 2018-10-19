#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "music_library.h"


struct song_node * table[27]; //i don't think this is supposed to go here but?

//find which linked list to go into
struct song_node *find_letter_array( char artist[100]){
  int n = 0;
  char *artistp = artist;
  printf("0\n");
  while( strcmp( table[n]->artist, artistp) < 0) { //seg fault is here??
    printf("2\n");
    n++;
  }
  printf("1\n");
  return table[n-1];
}

void add_song( char name[100], char artist[100]){
  insert_song( name, artist, find_letter_array(artist));
}

struct song_node *locate_song( char name[100], char artist[100]){
  return find_song( name, artist, find_letter_array(artist));
}

void find_artist( char artist[100]){ //printf whether artist is found or not
  if( first_song( artist, find_letter_array(artist)) == NULL)
    printf( "artist not found!");
  else
    printf( "artist found!");
}
//void print_letter( char letter){
//}
//void print_artist_songs( char artist[100]){
//}
void print_library(){
  int n = 0;
  while ( n < 27)
    print_list( table[n]);
}
void shuffled_playlist(){
  int n = 0;
  while( n < 4) {
    printf( random_song());
    n++;
  }
}
//struct song_node *delete_song( char name[100], char artist[100]){
//}
//struct song_node *clear_library(){
//}
