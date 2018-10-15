struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *n,int num );
struct song_node *alphabetize_artist();
struct song_node *alphabetize_song();
struct song_node *print_list();


