#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "songslibrary.h"
#include "songslist.h"


// Allocate enough memory for 27 linked lists, make sure each entry is an empty list.
struct song_node** init_library(){
  struct song_node** library = calloc(27, sizeof(struct song_node*));
  return library;
}
// Add song nodes.
void add_song(struct song_node** library, char* artist, char* name){
  int index = artist[0] - 97;
  // print_list(library[index]);
  if (library[index]){
    library[index] = insert_node_ordered(library[index], name, artist);
  }else{
    // linked list for this letter doesnt exist
    library[index] = make_song(name, artist);
  }
}
// Search for a song given song and artist name (return a pointer).
// Search for an artist (return a pointer).
// Print out all the entries under a certain letter.
// Print out all the songs of a certain artist
// Print out the entire library.
void print_library(struct song_node** library){
  int i;
  for (i = 0; i < 27; i++){
    if (library[i]){
      printf("%c: ", i + 97);
      print_list(library[i]);
    }
  }

}
// Shuffle - print out a series of randomly chosen songs.
// Delete a song
// Clear out all the linked lists in the library.
