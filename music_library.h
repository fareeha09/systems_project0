

void add_song( char name[100], char artist[100]);
struct song_node *find_song( char name[100], char artist[100]);
void find_artist( char artist[100]); //printf whether artist is found or not
void print_letter( char letter);
void print_artist_songs( char artist[100]);
void print_library();
void shuffled_playlist();
struct song_node *delete_song( char name[100], char artist[100]);
struct song_node *clear_library();

