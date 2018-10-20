#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

//struct song_node * table[27];

void add_song(struct song_node *arr[27], char name[100], char artist[100]);
struct song_node *locate_song(struct song_node *arr[27], char name[100], char artist[100]);
void find_artist( struct song_node *arr[27], char artist[100]); //printf whether artist is found or not
void print_letter( struct song_node *arr[27], char letter);
void print_artist_songs( struct song_node *arr[27], char artist[100]);
void print_library(struct song_node *table[27]);
void shuffled_playlist(struct song_node *table[27]);
void delete_song( struct song_node *arr[27], char name[100], char artist[100]);
void clear_library(struct song_node *table[27]);

#endif
