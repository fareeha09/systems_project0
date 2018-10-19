#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *insert_front(struct song_node *n, char name[100], char artist[100]);
struct song_node *insert_song(struct song_node *cur_node, char name0[100], char artist0[100]);
void print_list( struct song_node *cur_node);
struct song_node *find_song( char artist[100], char song_name[100], struct song_node *cur_node);
struct song_node *first_song( char artist[100], struct song_node *cur_node);
struct song_node *random_song();
struct song_node *remove_song( struct song_node *song);
struct song_node * free_list(struct song_node *first);

#endif
