#include <stdbool.h>
#if 0
/* List node data structure */
struct list_node {
	int elem; /* stores the value */
	struct list_node *next; /* pointer to the next element */
};
#endif
struct list_node; /* forward declaration */

/* Empty list, new list is a NULL pointer */

typedef struct list_node list_node_t;

/* create a new list and return the pointer to the new list */
struct list_node *list_init(void);

/* Destroy all the elements and the list pointer */
void list_destroy(struct list_node *listptr);

/* Insert new element to the beginning of the list */
struct list_node *list_insert_elem(struct list_node *listptr, int new_elem);

/* append new element to the end of the list */
struct list_node *list_append_elem(struct list_node *listptr, int new_elem);

/* Print elements of the list to standard out */
void list_print(struct list_node *listptr);

/* find element in list  return true if found else false*/
bool list_find_elem(struct list_node *listptr, int elem);

/* delete element from list */
struct list_node *list_del_elem(struct list_node *listptr, int elem);

/* add element in sorted order */
struct list_node *list_add_elem(struct list_node *listpts, int elem);

/* returns a new list of merged list in sorted order: input lists must be sorted */
struct list_node *list_merge_list(struct list_node *list1, struct list_node *list2);
