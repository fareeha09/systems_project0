#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "music_library.h"


//find which linked list to go into
struct song_node *find_letter_array(struct song_node *table[]; char artist[100]){
  char *artist0 = artist;
  char c = *artist0;   
  int index = c- 'A'; //ascii value of char - ascii value of anothe char gives the index
  return table[index]; //i tested this and it works^^
}

//add song nodes
void add_song(struct song_node *arr[27], char name[100], char artist[100]){
  insert_ordered(find_letter_array(arr, artist), name, artist);
}

//seach for a song given a song and artist name (return a pointer)
struct song_node *locate_song( char name[100], char artist[100]){
  return find_song( name, artist, find_letter_array(artist));
}

//search for an artist
void find_artist( char artist[100]){ //printf whether artist is found or not
  if( first_song( artist, find_letter_array(artist)) == NULL)
    printf( "artist not found!\n");
  else
    printf( "artist found!\n");
}

//print out all the songs of a certain letter
void print_letter( char letter){
    int i = 65; //ascii value of capital A
    while (letter != i){
      i++; 
     print_list(table[i-65]);
    }
}

//print out the songs of a certain artist
void print_artist_songs( char artist[100]){
  char *artistp = artist;
  struct song_node *cur_node = first_song( artist, find_letter_array(artist));
  if ( cur_node == NULL)
    printf( "artist doesn't exist\n");
  else {
    while(cur_node){
      if  (!strcmp( cur_node->artist, artistp)
	      printf( "%s, ", cur_node->name);
	  cur_node = cur_node->next;
  }
}
}

//print out entire library
void print_library(struct song_node *table[27]){
  int n = 0;
  while ( n < 27)
    print_list( table[n]);
    n++;
}

//shuffle and print out randomly chosen songs
void shuffled_playlist(struct song_node *table[27]){
  printf( "shuffled playlist: ");
  srand( time(NULL) );
  int n = 0;
  while( n < 4) {
	int num = rand() % 27;
	struct song_node *node = table[num];
    struct song_node *next_song = random_song(node);
    printf( "%s: \"%s\" | ", next_song->artist, next_song->name);
    n++;
  }
}

//delete a specified song
struct song_node *delete_song( char name[100], char artist[100]){
  remove_song( locate_song( name, artist)) ;
}

//clear the entire library
void clear_library(struct song_node *table[27]){
	int i=0;
	while(i < 27){
		free_list(table[i]);
		i++;
	}
}

int main(){
	
   printf("MUSIC LIBRARY TEST\n");
   printf("======================================\n");
   
   struct song_node * table[27];
   
   add_song(table, "Selena Gomez", "Come and Get It";
   add_song(table, "Demi Lovato", "Sorry not Sorry";
   add_song(table, "Billie Eilesh", "Lonely";

   printf("Testing print_library:\n");
   print_library(table);
   printf("___________________\n");
   
   printf("Testing print_list w/ null pointer:\n");
   struct song_node *locate = locate_song( "Sorry not Sorry", "Demi Lovato");
   print_list(locate);
   printf("Testing print_list w/ null pointer:\n");
   struct song_node *pointer = locate_song(NULL);
   printf("___________________\n");
   
   printf("Testing find_artist:\n"
   find_artist( char artist[100]); //printf whether artist is found or not
   if (find_artist( char artist[100])) printf(True); 
   printf("___________________\n");
   
   printf("Testing print_letter");
   print_letter( 'C' );
   printf("___________________\n");
   
   printf("Testing print artist songs");
   print_artist_songs( "Selena Gomez");
   printf("___________________\n");
   
   printf("Testing print_libary");
   print_library();
   printf("___________________\n");
   
   printf("Testing shuffled playlist");
   shuffled_playlist();
   printf(table);
   printf("___________________\n");
   
   printf("Testing delete song");
   struct song_node * n0 = delete_song( "Come and Get It", "Selena Gomez");
   clear_library();
   print_library(table);

}