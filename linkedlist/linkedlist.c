#include <stdlib.h>
#include <stdio.h>
/*
* Composite data structure
* self referential data structure
*/
struct node {
	int value;
	struct node *next;	
};

struct node *head; /* pointer to the first element of the list */

struct node *
allocate_new_node(int v)
{
	/* call malloc() to allocate memory  on heap */
	struct node *new_node; /*Pointer to the new Node */
	new_node = malloc(sizeof(struct node));	
	if(new_node == NULL) {
		fprintf(stderr, "malloc failed; Out of memory!\n");
		return NULL;
	}
	
	printf("new node %p \n", new_node);	
	/*initialize new node data members */
	new_node->value = v;
	new_node->next = NULL;
	return new_node;
}

void add_node_to_list(struct node **listptr /*in/out */, struct node *node /*in/out */) {
	/* insert new node at the beginning */
	if(*listptr == NULL) {
		*listptr = node;
		return;
	}
	node->next = *listptr;
	(*listptr) = node;
}

void print_list(struct node *listptr /*in */) {
	while(listptr != NULL) {
		printf("%d\n", listptr->value);
		listptr = listptr->next;	
	}
}




int main(int argc, int **argv) {
	head = NULL;
	/* read an Integer */

	int inp;
	//scanf("%d", &inp); /* read into inp */

	char input_buffer[80];
	struct node *new_node;
	
	do {

		//scanf("%d", &inp); /* read into inp */
		fgets(input_buffer, sizeof(input_buffer), stdin);
		inp = strtod(input_buffer, NULL);
		new_node = allocate_new_node(inp);
		add_node_to_list(&head, new_node);
		print_list(head);
	} while(inp != 0);
	
	/* free up the allocated memory  -memory leak */
	return 0;
}
	
