#include "plist.h"
#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2

// From fetchline.c 
char* ensure_capacity(char *buf, int *sz, int pos) {
  if (*sz == pos) {
    char *newbuf = (char*) realloc (buf, *sz * GROWTH_FACTOR); 
    if (newbuf == NULL) {
      free(buf);
      *sz = 0;
      return NULL;
    } else {
      *sz *= GROWTH_FACTOR;
      return newbuf;
    }
  } else {
    return buf;
  }
}


// From fetchline.c 
char* fetchline(void) {
  int pos = 0;
  int sz  = INITIAL_SIZE;
  char *buf = (char*) malloc(sizeof(char) * sz);
  if (buf == NULL) { return NULL; }
  char ch = getchar();
  while (ch != '\n') {
    buf = ensure_capacity(buf, &sz, pos);
    if (buf == NULL) { return NULL; }
    buf[pos++] = ch;
    ch = getchar();
  }
  buf = ensure_capacity(buf, &sz, pos);
  if (buf == NULL) { return NULL; }
  buf[pos++] = '\0';
  return buf;
}



void main (void) {
  plist_t * targetRing = make_list();
  plist_t * taggedList = make_list();
  printf("Enter a player's name (press enter to begin game):");
  char *name = fetchline();
  while (strcmp (name, "") != 0) {
    list_insert(targetRing,name);
    printf("Enter another player's name:");
    name = fetchline();
    
  }
  free (name); 

  
  printAsTargetRing(targetRing);
  printAsTaggedList(taggedList);
  printf("\n");

  while (list_size(targetRing)>1) {
  printf("There are %d people left!\n", list_size(targetRing));
  printf("Enter a target: ");
  name = fetchline ();
  if (list_remove (targetRing, name)) {
    printf("%s was tagged!\n",name);
    list_insert(taggedList,name);
  
  }
  else {
    printf("%s is not a target!", name);
  }
  printAsTargetRing(targetRing);
  printAsTaggedList(taggedList);
  printf("\n");
 
  }
  free_list (targetRing);
  free_list (taggedList);
    
}
