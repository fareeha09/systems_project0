struct song_node *insert_front(struct song_node *prev_front, char name[100], char artist[100]) {
  struct song_node *new_node = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  new_node->next = prev_front;
  return new_node;
}
struct song_node *insert_song_ordered( char name[100], char artist[100]) {
} 
void print_list( struct song_node *head) {
    
struct song_node *find_song( char artist[100], char song_name[100]);
struct song_node *first_song( char artist[100]);
struct song_node *random_song();
void remove_song( struct song_node *song);
struct song_node * free_list(struct song_node *first);
