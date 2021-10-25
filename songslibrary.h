#ifndef songslibrary_h
#define songslibrary_h

#include "songslist.h"
struct song_node** init_library();
void add_song(struct song_node** libary, char* name, char* artist);
void print_library(struct song_node** libary);

#endif
