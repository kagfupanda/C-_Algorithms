#include "listapi.hpp"

// using global namespace

list::list() {
	// initialze data members
	head = NULL;
}

//dtor
list::~list() {
	std::cout << "Enter: list dtor called \n";
	//delete all nodes and free up space
	/* traverse the list and free every node, finally the list pointer itself */
        list::node *cur;
        list::node *next;
        cur = head; /* initialize cur to listptr */
        while(cur != NULL) { /* Check point for NULL before dereferencing */
                next = cur->next; /* Never access pointer without first checking for NULL */    /* pointer to next element to be free */
                freemem(cur); /*free up current node */
                cur = next; /* make current to next */
        }
        return;
}

list::node *
list::allocmem(int elem) {
	list::node *new_node = new node;
	new_node->elem = elem;
	new_node->next = NULL;
	return new_node;	
}

void
list::freemem(list::node *ptr) {
	delete ptr;
}

void list::insert(int elem) {
	/* is list empty? */
        if(head == NULL) {
                head = allocmem(elem);
                return;
        }
        /* list not empty */
        list::node *new_node = allocmem(elem);
        new_node->next = head; /* add at beginning */
	head = new_node; /* head is the new listptr */
        return;
}

void 
list::append(int elem) {
	/* is list empty? */
        if(head == NULL) {
                head = allocmem(elem);
                return;
        }
        /* list not empty */
        list::node *cur = head; /* set current to list ptr */
        while(cur->next != NULL) {
                cur = cur->next; /* advance cur to next node */
        }
        /*cur.next is NULL, loop exited */
        list::node *new_node = allocmem(elem);
        cur->next = new_node; /* set cur->next to the new node */
        return; /* return listptr, no change */
}

void
list::print() {
	if(head == NULL)
                return;
        list::node *cur = head;
        /* print elem values in space seperated on the same line */
        while(cur != NULL) {
		std::cout << cur->elem << " ";
               // printf("%d ", cur->elem); /* no new line */
                cur = cur->next; /* move cur to next node */
        }
        //printf("\n");
	std::cout << std::endl;
        return;

}

bool
list::find(int elem) {
	/* check for empty list */
        if(head == NULL)
                return false;
        /* iterate through list, check element value */
        list::node *cur = head;
        while(cur != NULL) {
                if(cur->elem == elem) { /* found it */
                        return true;
                }
                cur = cur->next; /* advance to next */
        }
        return false; /* end of list reached */
}

void
list::del(int elem) {
	/* case 1: empty list */
        if(head == NULL) {
                return;
        }

        /* case 2: is it first element */
        if(head->elem == elem) { /* delete fist node update list head pointer */
                list::node *delnode = head; /* save node to free */
                head = head->next;
                /* free deleted node */
                freemem(delnode);
                return;
        }

        /* case 3 general case */
        list::node *prev = head;
        list::node *cur = head->next; /* listptr is not null */

        while (cur !=NULL ) {
                if(cur->elem == elem) {
                        prev->next = cur->next;
                        freemem(cur);
                        return;
                }
                prev = cur;
                cur = cur->next;
        }
        return;

}

void
list::add(int elem) {
	list::node *new_node = allocmem(elem);
        /* Case 1: empty list */
        if (head == NULL) {
                head = new_node;
                return;
        }

        /* Case 2: insert first? */
        if(head->elem > elem) { /* insert at beginning */
                new_node->next = head;
                return; /* new node becomes list */
        }

        /* case 3: middle */
        list::node *prev = head;
        list::node *cur = prev->next;

        while(cur != NULL) {
                if(cur->elem > elem) { /* insert new node before element */
                        prev->next = new_node;
                        new_node->next = cur;
                        return;
                }
        prev = cur;
        cur = cur->next;
        }

        /* case 4 append at the end of the list */
        prev->next = new_node;
        return;
}
