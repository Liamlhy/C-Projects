#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct pnode {
  char *name;
  struct pnode *next;
} pnode_t;

typedef struct plist {
  pnode_t *first;
} plist_t;

pnode_t* make_node(char *name, pnode_t *next);
plist_t* make_list();
void free_node(pnode_t *node);
void free_list(plist_t *list);
void list_insert(plist_t *list, char *name);
bool list_remove(plist_t *list, char *name);
int list_size(plist_t *list);
void printAsTargetRing(plist_t *list);
void printAsTaggedList(plist_t *list); 
