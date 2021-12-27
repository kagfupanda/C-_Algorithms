#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/* include the api header file */
#include "listapi.h"
#include "listimpl.h"

struct list_node *list_init(void) {
	return NULL; /* a new list is an empy list*/
#if 0
	struct list_node **new_list;
	new_list = malloc(sizeof(struct list_node *)); /* allocate psace for a pointer */
	*new_list = NULL; /* set pointer to NULL to indicate empty list */
	return (struct list_node *)new_list;
#endif
}

void list_destroy(struct list_node *listptr) {
	/* traverse the list and free every node, finally the list pointer itself */
	struct list_node *cur;
	struct list_node *next;
	cur = listptr; /* initialize cur to listptr */
	while(cur != NULL) { /* Check point for NULL before dereferencing */
		next = cur->next; /* Never access pointer without first checking for NULL */	/* pointer to next element to be free */
		free(cur); /*free up current node */
		cur = next; /* make current to next */
	}
	return;
}

/* static keyword hides the function from outside the file. So not external API */
static struct list_node *
alloc_new_node(int elem) {
	struct list_node *new_node = malloc(sizeof(*new_node));
	new_node->elem = elem;
	new_node->next = NULL;
	return new_node;
}
struct list_node *list_insert_elem(struct list_node *listptr, int new_elem) {
	/* is list empty? */
	if(listptr == NULL) {
		listptr = alloc_new_node(new_elem);
		return listptr;	
	}
	/* list not empty */
	struct list_node *new_node = alloc_new_node(new_elem);
	new_node->next = listptr; /* add at beginning */
	return new_node;
}

struct list_node *list_append_elem(struct list_node *listptr, int new_elem) {
	/* is list empty? */
	if(listptr == NULL) {
		listptr = alloc_new_node(new_elem);
		return listptr;
	}
	/* list not empty */
	struct list_node *cur = listptr; /* set current to list ptr */
	while(cur->next != NULL) {
		cur = cur->next; /* advance cur to next node */
	}
	/*cur.next is NULL, loop exited */
	struct list_node *new_node = alloc_new_node(new_elem);
	cur->next = new_node; /* set cur->next to the new node */
	return listptr; /* return listptr, no change */
}	

void list_print(struct list_node *listptr) {
	if(listptr == NULL)
		return;
	struct list_node *cur = listptr;
	/* print elem values in space seperated on the same line */
	while(cur != NULL) {
		printf("%d ", cur->elem); /* no new line */
		cur = cur->next; /* move cur to next node */
	}
	printf("\n");
	return;
}

bool list_find_elem(struct list_node * listptr, int elem) {
	/* check for empty list */
	if(listptr == NULL)
		return false;
	/* iterate through list, check element value */
	struct list_node *cur = listptr;
	while(cur != NULL) {
		if(cur->elem == elem) { /* found it */
			return true;
		}
		cur = cur->next; /* advance to next */
	}
	return false; /* end of list reached */
}

struct list_node * list_del_elem(struct list_node * listptr, int elem) {
	/* case 1: empty list */
	if(listptr == NULL) {
		return listptr;
	}
	
	/* case 2: is it first element */
	if(listptr->elem == elem) { /* delete fist node update list head pointer */
		struct list_node *delnode = listptr; /* save node to free */
		listptr = listptr->next;
		/* free deleted node */
		free(delnode);
		return listptr;
	}

	/* case 3 general case */
	struct list_node *prev = listptr;
	struct list_node *cur = listptr->next; /* listptr is not null */

	while (cur !=NULL ) {
		if(cur->elem == elem) {
			prev->next = cur->next;
			free(cur);
			return listptr;
		}
		prev = cur;
		cur = cur->next;
	}
	return listptr;
}

/* add elem in sorted order: ascending */
struct list_node *list_add_elem(struct list_node *listptr, int elem) {
	struct list_node *new_node = alloc_new_node(elem);
	/* Case 1: empty list */
	if (listptr == NULL) {
		listptr = new_node;
		return listptr;
	}

	/* Case 2: insert first? */
	if(listptr->elem > elem) { /* insert at beginning */
		new_node->next = listptr;
		return new_node; /* new node becomes list */
	}
	
	/* case 3: middle */
	struct list_node *prev = listptr;
	struct list_node *cur = prev->next;
	
	while(cur != NULL) {
		if(cur->elem > elem) { /* insert new node before element */
			prev->next = new_node;
			new_node->next = cur;
			return listptr;
		}
	prev = cur;
	cur = cur->next;
	}
	
	/* case 4 append at the end of the list */
	prev->next = new_node;
	return listptr;

}

struct list_node *list_merge_list(struct list_node *list1, struct list_node *list2) {
	/* create a new list */
	struct list_node *merged_list = list_init();
	struct list_node *cur1 = list1; /* iterator */
	struct list_node *cur2 = list2; /* iterator */
	
	while(cur1 != NULL && cur2 != NULL) { /* terminating condition */
		/* compare cur1 and cur2 elem */
		if(cur1->elem < cur2->elem) {
			merged_list = list_add_elem(merged_list, cur1->elem);
			cur1 = cur1->next;
		} else {
			merged_list = list_add_elem(merged_list, cur2->elem);
			cur2 = cur2->next;
		}
	}	
	/* check if cur1 is null */
	/* check if cur2 is null */
	while (cur1 != NULL) {
		merged_list = list_add_elem(merged_list, cur1->elem);
		cur1 = cur1->next;
	}

	while (cur2 != NULL) { /* add rest of list2 elem to merged list */
		merged_list = list_add_elem(merged_list, cur2->elem);
		cur2 = cur2->next;
	}
	
	return merged_list;
}
