#ifndef songslibrary_h
#define songslibrary_h

#include "songslist.h"
struct song_node** init_library();
void add_song(struct song_node** libary, char* name, char* artist);
struct song_node* get_song_in_library(struct song_node ** library, char* name, char* artist);
struct song_node* find_artist(struct song_node ** library, char* artist);
void print_letter(struct song_node** libary, char letter);
void print_artist(struct song_node ** library, char* artist);
void print_library(struct song_node** libary);
void delete_song_from_library(struct song_node ** library, char* artist, char* name);
void clear_library(struct song_node ** library);

#endif
