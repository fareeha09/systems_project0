#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "music_library.h"

int main(){
  //  char *p= "celine";	
  //  int i = (*p - "c");
   
  //   printf("%d\n", i);
   printf("LINKED LIST TESTS\n");
   printf("======================================\n");
   struct song_node * p0 = malloc(sizeof(struct song_node)); 
   struct song_node * p1 = malloc(sizeof(struct song_node));
   struct song_node * p2 = malloc(sizeof(struct song_node)); 
   struct song_node * p3 = malloc(sizeof(struct song_node));
   strcpy(p0->artist, "Celine Dion"); strcpy(p0->name, "Because You Loved Me"); p0->next= p1;
   strcpy(p1->artist, "Celine Dion"); strcpy(p1->name, "My Heart Will Go On"); p1->next= p2;
   strcpy(p2->artist, "Celine Dion"); strcpy(p2->name, "The Power of Love"); p2->next= NULL;
   
   printf("Testing print_list:\n");
   print_list(p0); 
   printf("___________________\n");
   
   printf("Testing print_list w/ null pointer:\n");
   print_list(NULL);
   printf("___________________\n");
   
   printf("Testing insert front:\n");
   struct song_node *new = NULL;
   new = insert_front(p0, "Grenade","Cruno Mars");
   print_list(new);
   printf("___________________\n");
   
   printf("Testing random song:\n");
   struct song_node  *rand = random_song(new);
   printf("printing random: %s by %s\n", rand->name, rand->artist);
   printf("___________________\n");

   printf("Testing first_song: \n");
   struct song_node *firstt = first_song("Celine Dion", new);
   printf("printing first song of Celine Dion's: %s \n", firstt->name);
   printf("___________________\n");

   printf("Testing first_song with name that doesn't exist: \n");
   struct song_node *firs = first_song("Tom", new);
   printf("printing first song of (doesn't exist): %s \n", firs->name);
   printf("___________________\n");
   
   printf("Testing find_song: \n");
   struct song_node *found = find_song( "My Heart Will Go On", "Celine Dion", p0);
   printf("song name: %s by %s\n", found->name, found->artist); 
   printf("___________________\n");

   printf("Testing find_song that doesn't exist: \n");
   struct song_node *find = find_song( "My", "Celine Dion", p0);
   printf("song name: %s \n", find->name); 
   printf("___________________\n");
   
   printf("Before Removal: \n");
   print_list(new);
   printf("\nAfter Removal of last element: \n");
   remove_song(new, p2);
   print_list(new);
   printf("\nAfter Removal of second element: \n");
   remove_song(new, p0);
   print_list(new);
   printf("\nAfter Removal of first element: \n");
   remove_song(new, p1);
   print_list(new);
   printf("\nAfter Removal of last element: \n");
   remove_song(new, p3);
   print_list(new);
   printf("___________________\n");
   
   printf("Testing insert song in order:\n\n");
   struct song_node *new0 = NULL;
   new0 = insert_ordered(new, "Just the Way You Are" , "Cruno Mars");
   print_list(new);
   
   struct song_node *new1 = NULL;
   new1 = insert_ordered(new, "Because You Loved Me" , "Celine Dion");
   print_list(new0);
   
   struct song_node *new2 = NULL;
   new = insert_ordered(new, "Grenade" , "Cruno Mars");
   print_list(new2);
   printf("___________________\n");
   
   printf("Freeing the List: \n");
   //   struct song_node *freed= free_list(new0);
   print_list(new2);

   printf("\n\nMUSIC LIBRARY TEST\n");
   printf("======================================\n");
   
   struct song_node * table[27]= { NULL };;
   
   table[find_letter_array(table, "Selena Gomez")] = add_song(table, "Wolves", "Selena Gomez");
   table[find_letter_array(table, "Selena Gomez")] = add_song(table, "Come and Get It", "Selena Gomez");
   table[find_letter_array(table, "Drake")] = add_song(table, "In my Feelings", "Drake");
   table[find_letter_array(table, "Drake")] = add_song(table, "God's Plan", "Drake");
   table[find_letter_array(table, "Demi Lovato")] = add_song(table, "Sorry not Sorry", "Demi Lovato"); 
   table[find_letter_array(table, "Billie Eilish")] = add_song(table, "Lonely", "Billie Eilish"); 
   table[find_letter_array(table, "Cardi B")] = add_song(table, "I Like It", "Cardi B"); 
   table[find_letter_array(table, "Migos")] = add_song(table, "Walk It Talk It", "Migos"); 
   table[find_letter_array(table, "Maroon 5")] = add_song(table, "Girls Like You", "Maroon 5");
   table[find_letter_array(table, "Ariana Grande")] = add_song(table, "No Tears Left to Cry", "Ariana Grande");
   table[find_letter_array(table, "Hailee Steinfield")] = add_song(table, "Most Girls", "Hailee Steinfield"); 
   table[find_letter_array(table, "XXXTentacion")] = add_song(table, "SAD!", "XXXTentacion"); 
   table[find_letter_array(table, "Lil Dicky")] = add_song(table, "Freaky Friday", "Lil Dicky");
   table[find_letter_array(table, "Post Malone")] = add_song(table, "Better Now", "Post Malone");
   table[find_letter_array(table, "Juice Wrld")] = add_song(table, "Lucid Dreams", "Juice Wrld"); 
   table[find_letter_array(table, "Eminem")] = add_song(table, "Rap God", "Eminem"); 
   table[find_letter_array(table, "Travis Scott")] = add_song(table, "Yosemite", "Travis Scott");
   
   
   printf("Testing print_library:\n");
   print_library(table);
   printf("___________________\n");
   
   printf("Testing locate_song:\n");
   struct song_node *locate = locate_song( table, "Sorry not Sorry", "Demi Lovato");
   print_list(locate);
   printf("Testing locate_song that doesn't exist:\n");
   struct song_node *pointer = locate_song(table, "D", "D");
   print_list(pointer);
   printf("___________________\n");
   
   printf("Testing find_artist w/ existing artist:\n");
   find_artist( table, "Demi Lovato"); //printf whether artist is found or not
   printf("Testing find_artist w/ non-existent artist:\n");
   find_artist( table, "No");
   printf("___________________\n");
    
   printf("Testing print_letter 'C' (null):\n");
   print_letter( table, 'C' );
   printf("Testing print_letter 'B':\n");
   print_letter( table, 'B' );
   printf("___________________\n");
   
   printf("Testing print artist songs w/ Selena Gomez:\n");
   print_artist_songs(table, "Selena Gomez");
   printf("Testing print artist songs w/ non-existent artist:\n");
   print_artist_songs(table, "No");
   printf("___________________\n");
   
   printf("Testing shuffled playlist:\n");
   shuffled_playlist(table); 
   printf("___________________\n");
   
   printf("Testing delete song:\n");
   delete_song( table, "Come and Get It", "Selena Gomez");
   printf("___________________\n");

   printf("Testing clear library: \n");
   clear_library(table);

}