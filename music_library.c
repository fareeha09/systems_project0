#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "music_library.h"


//find which linked list to go into
int find_letter_array(struct song_node *table[27], char artist[100]){
  char *artist0 = artist;
  char c = *artist0;
  int index = c - 'A'; //ascii value of char - ascii value of anothe char gives the index
  return index;
}


//add song nodes
struct song_node *add_song(struct song_node *arr[27], char name[100], char artist[100]){
    int index = find_letter_array(arr, artist);
	struct song_node *ar = arr[find_letter_array(arr, artist)]; 
	struct song_node *new= insert_front(ar, name, artist);
	return new;
    // else
      // insert_ordered(find_letter_array(arr, artist), name, artist);
     
}

//seach for a song given a song and artist name (return a pointer)
struct song_node *locate_song(struct song_node *arr[27], char name[100], char artist[100]){
  return find_song( name, artist, arr[find_letter_array( arr, artist)]);
}

//search for an artist
void find_artist(struct song_node *arr[27], char artist[100]){ //printf whether artist is found or not
  if( !first_song( artist, arr[find_letter_array( arr, artist)]))
    printf(" "); //already prints from first_song func
  else
    printf( "artist found!\n");
}

//print out all the songs of a certain letter
void print_letter(struct song_node *arr[27], char letter){
    int i = 65; //ascii value of capital A
    while (letter != i){
     i++; 
    } print_list(arr[i-65]);
}

//print out the songs of a certain artist
void print_artist_songs( struct song_node *arr[27], char artist[100]){
  char *artistp = artist;
  struct song_node *cur_node = first_song( artist, arr[find_letter_array( arr, artist)]);
  if ( cur_node == NULL)
    printf( "artist doesn't exist\n");
  else {
    while(cur_node){
      if  (!strcmp( cur_node->artist, artistp)) {
	  printf( "%s, \n", cur_node->name);
	  cur_node = cur_node->next;
	}
    }
  }
}


//print out entire library
void print_library(struct song_node *table[27]){
  int n = 0;
  while ( n < 27) {
    printf(" table[%d] : ", n);
	print_list( table[n]);
    n++;
}}

void delay(int number_of_seconds) //copied and pasted from online website
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
}

//shuffle and print out randomly chosen songs
void shuffled_playlist(struct song_node *table[27]){
  printf( "shuffled playlist: ");
  srand( time(NULL) );
  int n = 0;
  while( n < 4) {
	delay(rand() % 10);
	int num = rand() % 27;
	//time
	//printf("rand num: %d, %d\n", r, num);
	struct song_node *node = table[num];
	if(node != NULL) {
		struct song_node *next_song = random_song(node);
		if(next_song) {
			printf( "%s: \"%s\" \n", next_song->artist, next_song->name);
		}
		n++;
	}
  }
}

//delete a specified song
void delete_song( struct song_node *arr[27], char name[100], char artist[100]){
   remove_song( locate_song( arr, name, artist), arr[find_letter_array( arr, artist)]);
}

//clear the entire library
void clear_library(struct song_node *table[27]){
	int i=0;
	while(i < 27){
		free_list(table[i]);
		i++;
	}
}
