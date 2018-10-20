#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "music_library.h"

int main(){
   char *p= "celine";	
   int i = (*p - "c");
   
   printf("%d\n", i);
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
   struct song_node *new = malloc(sizeof(struct song_node));
   new = insert_front(p0, "Grenade","Bruno Mars");
   print_list(new);
   printf("___________________\n");
   
   printf("Testing random song:\n");
   struct song_node  *rand = random_song(new);
   printf("printing random: %s \n", rand);
   printf("___________________\n");

   printf("Testing first_song: \n");
   struct song_node *firstt = first_song("Celine Dion", new);
   printf("printing first song of Celine Dion's: %s \n", firstt);
   printf("___________________\n");

   printf("Testing first_song with name that doesn't exist: \n");
   struct song_node *firs = first_song("Tom", new);
   printf("printing first song of (doesn't exist): %s \n", firs);
   printf("___________________\n");
   
   printf("Testing find_song: \n");
   struct song_node *found = find_song( "My Heart Will Go On", "Celine Dion", p0);
   printf("song name: %s \n", found); 
   printf("___________________\n");

   printf("Testing find_song that doesn't exist: \n");
   struct song_node *find = find_song( "My", "Celine Dion", p0);
   printf("song name: %s \n", find); 
   printf("___________________\n");
   
   printf("Before Removal: \n");
   print_list(new);
   printf("\nAfter Removal of last element: \n");
   remove_song(new, p2);
   print_list(new);
   printf("\nAfter Removal of second element: \n");
   remove_song(new, p0);
   print_list(new);
   printf("___________________\n");
   
   printf("Testing insert song in order:\n\n");
   struct song_node *new0 = malloc(sizeof(struct song_node));
   new0 = insert_ordered(new, "Just the Way You Are" , "Bruno Mars");
   print_list(new0);
   
   struct song_node *new1 = malloc(sizeof(struct song_node));
   new1 = insert_ordered(new, "Because You Loved Me" , "Celine Dion");
   print_list(new1);
   
   struct song_node *new2 = malloc(sizeof(struct song_node));
   new2 = insert_ordered(new, "Grenade" , "Bruno Mars");
   print_list(new2);
   printf("___________________\n");
   
   printf("Freeing the List: \n");
   struct song_node *freed= free_list(new0);
   print_list(freed);
   

   }




