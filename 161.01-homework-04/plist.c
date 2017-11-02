#include "plist.h"

pnode_t *make_node (char *name , pnode_t *next) {
  pnode_t *ret =  (pnode_t*) malloc (sizeof(pnode_t));
    ret->name = name;
    ret->next = next;
  return ret;
}

plist_t *make_list (void) {
  plist_t *ret = (plist_t*) malloc (sizeof (plist_t));
  ret->first = NULL;
  return ret;
}


void free_node(pnode_t *node) {
  free (node->name);
  free (node);
}

void free_list (plist_t *l) {
  pnode_t *cur = l-> first;
  while (cur != NULL) {
    pnode_t *t = cur->next;
    free_node (cur);
    cur = t;
  }
  free (l);
}

void list_insert(plist_t *list, char *name) {
  pnode_t *n = make_node(name, NULL);
  if (list->first == NULL) {
    list->first = n;
  } else {
    pnode_t *cur = list->first;
    while (cur->next != NULL) { cur = cur->next; }
    cur->next = n;
  }
}

bool list_remove (plist_t *list, char *name) {
  if (list->first == NULL) {
    return false;
  }
  else if (strcmp (name, list->first->name) == 0) {
    pnode_t *temp = list->first;
    list->first = list->first->next;
    free_node(temp);
    return true;
  }
  else {
    pnode_t *cur = list->first;
    while (cur->next != NULL) {
      if (strcmp (cur->next->name, name) == 0) {
        pnode_t *temp = cur->next;
        cur->next = cur->next->next;
        free_node(temp);
        return true;
      }
      cur = cur->next;
    }
    return false;
  }
}

int list_size (plist_t *list) {
  int count = 0 ;
  pnode_t *cur = list->first;
  while (cur != NULL) {
    count++;
    cur= cur-> next;
  }
   return count;
} 

void printAsTargetRing (plist_t *list) {
  if (list->first==NULL) {
    printf("There are no targets left!\n");
  }
  else if (list->first->next== NULL) {
    printf ("%s is the final person remaining!\n", list->first->name);
  }
  else {
    printf("Target Ring: \n");
    pnode_t *cur = list->first;
    while (cur->next!= NULL) {
      printf("  %s is stalking %s \n",cur->name, cur->next->name); 
      cur=cur->next; 
    }
    printf ("  %s is stalking %s \n",cur->name, list->first->name);
  }
}

void printAsTaggedList(plist_t *list) {
  if (list->first == NULL) {
    printf("No people have been tagged yet!\n");
  }
  else {
    printf("Tageed List: \n");
    pnode_t *cur = list->first;
    while (cur != NULL) {
      printf ("  %s\n", cur->name);
      cur = cur->next;
    }
  }
}
