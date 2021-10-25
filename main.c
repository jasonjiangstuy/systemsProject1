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
  insert_node_ordered(testlist, "alive", "pearl jam");
  insert_node_ordered(testlist, "even flow", "pearl jam");
  insert_node_ordered(testlist, "yellow ledbetter", "pearl jam");
  insert_node_ordered(testlist, "time", "pink floyd");
  insert_node_ordered(testlist, "paranoid android", "radiohead");
  insert_node_ordered(testlist, "street spirit (fade out)", "radiohead");
  print_list(testlist);
  printf("====================================\n");

  printf("Testing print_node:\n");
  printsong(testlist);

  printf("\n====================================\n");

  printf("Testing find_node:\n");
  printf("looking for [pearl jam: even flow]\n");
  struct song_node * target = get_song(testlist, "pearl jam", "even flow");
  if (target){
    printf("node found!");
    printsong(target);
  }else{
    printf("FAIL find_node1\n");
  }

  printf("  looking for [pearl jam: daughter] \n");
  target = get_song(testlist, "pearl jam", "daughter");
  if (target == NULL){
    printf("node not found!\n");
  }else{
    printf("FAIL find_node2\n");
  }

  printf("====================================\n Testing find_artist:\n");
  printf("looking for [pink floyd]\n");
  target = get_artist_first_song(testlist, "pink floyd");
  if (target){
    printf("artist found!\n");
    print_list(target);
  }else{
    printf("FAIL find_node1\n");
  }

  printf("looking for [pearl jam]\n");
  target = get_artist_first_song(testlist, "pearl jam");
  if (target){
    printf("artist found!\n");
    print_list(target);
  }else{
    printf("FAIL find_node1\n");
  }

  printf("looking for [presidents of the united states of america]\n");
  target = get_artist_first_song(testlist, "pearl jam");
  if (target){
    printf("artist not found!\n");
    print_list(target);
  }else{
    printf("FAIL find_node1\n");
  }

printf("====================================\n");

printf("Testing songcmp (helper function):\n");
printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
printf("%d\n", compare_nodes(get_song(testlist, "pearl jam", "even flow"), "even flow", "pearl jam"));

printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n");
printf("%d\n", compare_nodes(get_song(testlist, "pearl jam", "even flow"), "alive", "pearl jam"));

printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n");
printf("%d\n", compare_nodes(get_song(testlist, "pearl jam", "alive"), "even flow", "pearl jam"));

printf("Comparing [pearl jam: even flow] to [pearl jam: time]\n");
printf("%d\n", compare_nodes(get_song(testlist, "pearl jam", "even flow"), "even flow", "time"));
printf("^^ correct for the way i built it\n");

printf("====================================\n");
printf("Testing random:\n");
printsong(get_random_song(testlist));
printf("\n");
printsong(get_random_song(testlist));
printf("\n");
printsong(get_random_song(testlist));
printf("\n");
printsong(get_random_song(testlist));
printf("\n");

printf("====================================\n\n");

printf("Testing remove:\n");
printf("Removing [ac/dc: thunderstruck]\n");
testlist = remove_node(testlist, "thunderstruck", "ac/dc");
printf("test\n" );
print_list(testlist);

printf("Removing [radiohead: street spirit (fade out)]\n");
testlist = remove_node(testlist, "street spirit (fade out)", "radiohead");
print_list(testlist);

printf("Removing [pearl jam: yellow ledbetter]\n");
testlist = remove_node(testlist, "yellow ledbetter", "pearl jam");
print_list(testlist);

printf("Removing [pearl jam: yellow ledbetter]\n");
testlist = remove_node(testlist, "yellow ledbetter", "pearl jam");
print_list(testlist);

printf("Testing free_list\n");
testlist = free_list(testlist);
print_list(testlist);

printf("MUSIC LIBRARY TESTS\n");
printf("====================================\n");
struct song_node ** library = init_library();
add_song(library, "ac/dc", "thunderstruck");
add_song(library, "pearl jam", "alive");
add_song(library, "pearl jam", "even flow");
add_song(library, "pearl jam", "yellow ledbetter");
add_song(library, "pink floyd", "time");
add_song(library, "radiohead", "paranoid android");
add_song(library, "radiohead", "street spirit (fade out)");

printf("Testing print_library\n");
print_library(library);

printf("Testing print_letter\n");
printf("a\n");
print_letter(library, 'a');
printf("b\n");
print_letter(library, 'b');
printf("p\n");
print_letter(library, 'p');

printf("Testing find:\n");

printf("looking for [pearl jam: alive]\n");
target = get_song_in_library(library, "alive", "pearl jam");
if (target){
  printf("song found!\n");
  printsong(target);
}else{
  printf("FAIL find_node1\n");
}

printf("\nlooking for [pearl jam: time]\n");
// target = NULL;
target = get_song_in_library(library, "time", "pearl jam");

if (target == NULL){
  printf("song not found\n");
}else{
  printf("FAIL find_node1\n");
}

printf("====================================\n");
printf("Testing find artist:\n");
printf("\nlooking for [pearl jam]\n");
target = find_artist(library, "pearl jam");
if (target){
  printf("artist found!\n");
  print_list(target);
}else{
  printf("FAIL find artist\n");
}
printf("\nlooking for [pink floyd]\n");
target = find_artist(library, "pink floyd");

if (target){
  printf("artist found!\n");
  print_list(target);
}else{
  printf("FAIL find artist\n");
}

printf("\nlooking for [looking for [bob dylan]]\n");
target = find_artist(library, "looking for [bob dylan]");

if (target == NULL){
  printf("artist not found\n");
}else{
  printf("FAIL find_artist\n");
}

printf("==================================== \n Testing remove_song \n");

printf("removing: [pearl jam: alive]");
delete_song_from_library(library, "pearl jam", "alive");
print_library(library);
printf("removing: [pearl jam: yellow ledbetter]");
delete_song_from_library(library, "pearl jam", "yellow ledbetter");
print_library(library);

printf("Testing clear_library:\n");
clear_library(library);
printf("Library after clear:\n" );
print_library(library);

printf("Adding songs to empty library");
add_song(library, "ac/dc", "thunderstruck");
add_song(library, "pearl jam", "alive");
add_song(library, "pearl jam", "even flow");
add_song(library, "pearl jam", "yellow ledbetter");
add_song(library, "pink floyd", "time");
print_library(library);

printf("====================================\n");

printf("Testing print_artist:\n");
printf("Printing [pearl jam]\n" );
print_artist(library, "pearl jam");
printf("Printing [ac/dc]\n" );
print_artist(library, "ac/dc");
printf("Printing [radiohead]\n" );
print_artist(library, "radiohead");
printf("====================================\n");
printf("Testing shuffle\n");
shuffle(library, 3);


  return 0;
}
