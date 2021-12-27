#include "listapi.hpp"
#include <iostream>

// using global namespace

template<typename T>

list<T>::list() {
	// initialze data members
	head = NULL;
}

//dtor
template<typename T>
list<T>::~list() {
	//delete all nodes and free up space
	std::cout <<"ENTER: list dtor called \n";
	/* traverse the list and free every node, finally the list pointer itself */
        list<T>::node *cur;
        list<T>::node *next;
        cur = head; /* initialize cur to listptr */
        while(cur != NULL) { /* Check point for NULL before dereferencing */
                next = cur->next; /* Never access pointer without first checking for NULL */    /* pointer to next element to be free */
                freemem(cur); /*free up current node */
                cur = next; /* make current to next */
        }
        return;
}

template <typename T>
typename list<T>::node *
list<T>::allocmem(T elem) {
	list<T>::node *new_node = new node;
	new_node->elem = elem;
	new_node->next = NULL;
	std::cout << " return allocmem: " << new_node << std::endl;
	return new_node;	
}

template<typename T>
void
list<T>::freemem(list<T>::node *ptr) {
	std::cout<< "Enter: fremem: " << ptr << std::endl;
	delete ptr;
}

template <typename T>
void 
list<T>::insert(T elem) {
	/* is list empty? */
        if(head == NULL) {
                head = allocmem(elem);
                return;
        }
        /* list not empty */
        list<T>::node *new_node = allocmem(elem);
        new_node->next = head; /* add at beginning */
	head = new_node; /* head is the new listptr */
        return;
}

template <typename T>
void 
list<T>::append(T elem) {
	/* is list empty? */
        if(head == NULL) {
                head = allocmem(elem);
                return;
        }
        /* list not empty */
        list<T>::node *cur = head; /* set current to list ptr */
        while(cur->next != NULL) {
                cur = cur->next; /* advance cur to next node */
        }
        /*cur.next is NULL, loop exited */
        list<T>::node *new_node = allocmem(elem);
        cur->next = new_node; /* set cur->next to the new node */
        return; /* return listptr, no change */
}

template<typename T>
void
list<T>::print() {
	if(head == NULL)
                return;
        list<T>::node *cur = head;
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

template<typename T>
bool
list<T>::find(T elem) {
	/* check for empty list */
        if(head == NULL)
                return false;
        /* iterate through list, check element value */
        list<T>::node *cur = head;
        while(cur != NULL) {
                if(cur->elem == elem) { /* found it */
                        return true;
                }
                cur = cur->next; /* advance to next */
        }
        return false; /* end of list reached */
}

template<typename T>
void
list<T>::del(T elem) {
	/* case 1: empty list */
        if(head == NULL) {
                return;
        }

        /* case 2: is it first element */
        if(head->elem == elem) { /* delete fist node update list head pointer */
                list<T>::node *delnode = head; /* save node to free */
                head = head->next;
                /* free deleted node */
                freemem(delnode);
                return;
        }

        /* case 3 general case */
        list<T>::node *prev = head;
        list<T>::node *cur = head->next; /* listptr is not null */

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

template<typename T>
void
list<T>::add(T elem) {
	list<T>::node *new_node = allocmem(elem);
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
        list<T>::node *prev = head;
        list<T>::node *cur = prev->next;

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
