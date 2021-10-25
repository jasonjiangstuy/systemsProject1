#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "songslist.h"

struct song_node * insert_start(struct song_node *start ,char* name, char *artist){
  struct song_node *new = make_song(name, artist);
  new -> next = start;
  return new;
}
int compare_nodes(struct song_node* target, char * name, char *artist){
  // printf("compare_nodes\n");

  int comparison = strcmp(target -> artist, artist);
  if (comparison < 0){
    return 1;
    //keep going
  }else if(comparison > 0){
    return 0;
    // stop
  }else{
    if (strcmp(target -> name, name) < 0){
      return 1;
    }else{
      return 0;
    }
  }
}

struct song_node * insert_node_ordered(struct song_node* start, char * name, char *artist){
  struct song_node* previous = NULL;
  struct song_node* target = start;

  while (target && compare_nodes(target, name, artist)){
    previous = target;
    target = target -> next;
  }
  if (previous != NULL){
    // printf("name: %s, artist: %s\n", name, artist);

    previous -> next = make_song(name, artist);
    // printsong(previous -> next);
    (previous -> next) -> next= target;
    return(start);
  }else{
    return(insert_start(start, name, artist));
  }
}

void print_list(struct song_node *p){
  printf("[");
  while(p != NULL){
    printsong(p);
    p = p -> next;
    // if (p != NULL){    }
    printf("|");
  }
  printf("]\n");

}

struct song_node * get_song(struct song_node* start, char * artis, char * nam){
  // printf("get song: %s by %s\n", nam, artis);
  struct song_node * target = start;
  while (target != NULL) {
    // printsong(target);
    // printf("%s: %d %s: %s: %d\n", target -> artist, strcmp(target -> artist, artis), target -> name, nam, strcmp(target -> name, nam));
    if (strcmp(target -> artist, artis) == 0 && strcmp(target -> name, nam) == 0){
      return target;
    }
    target = target-> next;
  }
  return NULL;
}
struct song_node * get_artist_first_song(struct song_node* start, char * artis){
  struct song_node * target = start;
  while (target != NULL) {
    if (strcmp(target -> artist, artis) == 0){
      return target;
    }
    target = target-> next;
  }
  return NULL;

}

// assume rand is working
struct song_node * get_random_song(struct song_node* start){
  int length = 0;
  struct song_node* target = start;
  while (target) {
    length ++;
    target = target -> next;
  }
  int num = rand() % (length);
  int i;

  target = start;
  for (i = 0; i < num; i++){
    target = target -> next;
  }
  return target;
}



struct song_node * free_list(struct song_node *start){
  struct song_node *target = start;
  struct song_node *holdnext;
  while (target != NULL) {
    holdnext = target -> next;
    free(target);
    target = holdnext;
    /* code */
  }
  return target;
}
// Write a function that prints out variables of your structs type in a reasonable way.
void printsong(struct song_node *s){
  printf("{%s, %s}", s->artist, s->name);
}

// Write a function that creates a new struct in heap memory, it should have paramteters appropraite to your struct.
struct song_node * make_song(char* nam, char *artis) {
  struct song_node *n = malloc(sizeof(struct song_node));
  strcpy(n->name, nam);
  strcpy(n->artist, artis);
  n->next = NULL;
  return n;
}

// WIP
struct song_node * remove_node(struct song_node *start, char* nam, char* artis){
  struct song_node * target = start;
  struct song_node * previous = NULL;
  while (target) {
    // printf("before stagfallinside\n");
    // printsong(target);
    if (strcmp(target -> name, nam) == 0 && strcmp(target -> artist, artis) == 0){
      // printf("after stagfall\n");
      if (previous != NULL){
        // printf("after stagfall\n");
        previous -> next = target -> next;
        free(target);
      }else{
        start = target -> next;
        free(target);

      }
      return start;
    }
    previous = target;
    target = target-> next;

  }
  return start;

}
