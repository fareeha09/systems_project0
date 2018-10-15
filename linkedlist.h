struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *insert_front(struct song_node *n, char name[100], char artist[100]);
struct song_node *insert_song( char name[100], char artist[100]);
void print_list( struct song_node *head);
struct song_node *find_song( char artist[100], char song_name[100]);
struct song_node *first_song( char artist[100]);
struct song_node *random_song();
void remove_song( struct song_node *song);
struct song_node * free_list(struct song_node *first);
