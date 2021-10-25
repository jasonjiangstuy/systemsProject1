#ifndef songslist_h
#define songslist_h

struct song_node{
char name[100];
char artist[100];
struct song_node *next;
};

// headers
struct song_node * insert_start(struct song_node *start , char * name, char *artist);
// 0 if we should put the node here 1, keep going
int compare_nodes(struct song_node* target, char * name, char *artist);
struct song_node * insert_node_ordered(struct song_node* node, char * name, char *artist);
void printsong(struct song_node *s);
struct song_node * get_song(struct song_node* start, char * artist, char * name);
struct song_node * get_artist_first_song(struct song_node* start, char * artist);
// assume rand is working
struct song_node * get_random_song(struct song_node* start);
struct song_node * make_song(char* nam, char *artis);
void print_list(struct song_node *p);
struct song_node * free_list(struct song_node *start);
struct song_node * remove_node(struct song_node *start, char* name, char* artist);

#endif
