#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "songslibrary.h"
#include "songslist.h"
int main() {
  srand(time(NULL));

  printf("LINKED LIST TESTS\n====================================\n");

  printf("Testing print_list:\n");
  struct song_node * testlist = make_song("thunderstruck", "ac/dc");
  insert_node_ordered(testlist, "pearl jam", "alive");
  insert_node_ordered(testlist, "pearl jam", "even flow");
  insert_node_ordered(testlist, "pearl jam", "yellow ledbetter");
  insert_node_ordered(testlist, "pink floyd", "time");
  insert_node_ordered(testlist, "radiohead", "paranoid android");
  insert_node_ordered(testlist, "radiohead", "street spirit (fade out)");
  print_list(testlist);
  printf("====================================\n");

  printf("Testing print_node:\n");
  printsong(testlist);

  printf("\n====================================\n");

  printf("Testing find_node:\n");
  printf("looking for [pearl jam: even flow]");
  if (get_song(testlist)){
    
  }else{
    printf("FAIL find_node1\n");
  }


  // test add and print out songs libary
  struct song_node ** library = init_library();
  add_song(library, "ac/dc", "thunderstruck");
  add_song(library, "pearl jam", "alive");
  add_song(library, "pearl jam", "even flow");
  add_song(library, "pearl jam", "yellow ledbetter");
  add_song(library, "pink floyd", "time");
  add_song(library, "radiohead", "paranoid android");
  add_song(library, "radiohead", "street spirit (fade out)");
  // print_library(library);

  return 0;
}
