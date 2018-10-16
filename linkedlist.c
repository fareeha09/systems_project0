struct song_node *insert_front(struct song_node *prev_front, char name[100], char artist[100]) {
  struct song_node *new_node = malloc( sizeof( struct song_node));
  strcpy( new_node->name, name);
  strcpy( new_node->artist, artist);
  new_node->next = prev_front;
  return new_node;
}
struct song_node *insert_song_ordered( char name[100], char artist[100]) {
}
void print_list( struct song_node *cur_node) {
  printf( "song list: ");
  while( cur_node) {
    printf( "%s by %s,", cur_node->name, cur_node->artist);
    cur_node = cur_node->next;
  }
  printf( "no next\n");
}
    
struct song_node *find_song( char artist[100], char song_name[100], struct song_node *cur_node) {
  char *artistp = &artist;
  while( strcmp( artistp, cur_node)) {
    cur_node = cur_node->next;
  }
  char *songp = &song_name;
  while( strcmp( songp, cur_node)) {
    if( strcmp( artistp, cur_node))
      return null;
    cur_node = cur_node->next;
  }
  return cur_node;
}
   
struct song_node *first_song( char artist[100]);
struct song_node *random_song();
void remove_song( struct song_node *song);
 
struct song_node * free_list(struct song_node *cur_node) {
    while( cur_node) {
    struct node *next_node = cur_node->next;
    free( cur_node);
    cur_node = next_node;
  }
  return cur_node;
}

