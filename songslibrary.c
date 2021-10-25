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
  if (index < 0 || index > 26 ){
    index = 26;
  }
  if (library[index]){
    library[index] = insert_node_ordered(library[index], name, artist);
  }else{
    // linked list for this letter doesnt exist
    library[index] = make_song(name, artist);
  }
}
// Search for a song given song and artist name (return a pointer).
struct song_node * get_song_in_library(struct song_node ** library, char* name, char* artist){
  int index = artist[0] - 97;
  if (index < 0 || index > 26 ){
    index = 26;
  }
  print_list(library[index]);
  struct song_node* result = get_song(library[index], artist, name);
  // printf("test4\n");
  return result;
}
// Search for an artist (return a pointer).
struct song_node* find_artist(struct song_node ** library, char* artist){
  int index = artist[0] - 97;
  if (index < 0 || index > 26 ){
    index = 26;
  }
  struct song_node* result = get_artist_first_song(library[index], artist);
  return result;
}
// Print out all the entries under a certain letter.
void print_letter(struct song_node** library, char letter){
  print_list(library[letter - 97]);
}
// Print out all the songs of a certain artist
void print_artist(struct song_node ** library, char* artist){
  struct song_node* target = find_artist(library, artist);
  printf("%s: ", artist);
  while (target && strcmp(target -> artist, artist) == 0){
    printsong(target);
    printf(" ");
    target = target -> next;
  }
}

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
void shuffle(struct song_node ** library, int num_of_songs){
  // print_library(library);
  int i;
  int sum = 0;
  for (i = 0; i < 27; i ++){
    struct song_node * target = library[i];
    while (target != NULL){
      sum ++;
      target = target -> next;
    }
  }
  struct song_node* all_songs[sum];
  sum = 0;
  for (i = 0; i < 27; i ++){
    struct song_node * target = library[i];
    while (target != NULL){
      all_songs[sum] = target;
      sum ++;
      target = target -> next;
    }
  }
  // printf("%d\n", sum);
  for (i = 0; i < num_of_songs; i ++){
    int num = rand() % (sum);
    // printf("num: %d\n", num);
    printsong(all_songs[num]);
    printf("\n");
  }
}

// Delete a song
void delete_song_from_library(struct song_node ** library, char* artist, char* name){
  int index = artist[0] - 97;
  if (index < 0 || index > 26 ){
    index = 26;
  }
  library[index] = remove_node(library[index], name, artist);

}
// Clear out all the linked lists in the library.
void clear_library(struct song_node ** library){
  int i;
  for (i = 0; i < 27; i++){
    if (library[i]){
      library[i] = free_list(library[i]);
    }
  }
}
