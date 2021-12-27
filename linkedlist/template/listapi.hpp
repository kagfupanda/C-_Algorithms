#ifndef _LISTAPI_HPP_INCLUDED_
#define _LISTAPI_HPP_INCLUDED_
#include <iostream>

/* using global namespace */

// A 'class' is same as 'stuct' EXCEPT;
// by default all members of 'class' private but in struct they are public
template <typename T>
class list {
public:
	// constructor (init)
	list(); 
	// destructor (dtor)
	~list(); 
	
	// insert elem at the beginning
	void insert(T elem);
	
	// append elemt at the end
	void append(T elem);
	
	//print list to stdout
	void print();
	
	// find element
	bool find(T elem);

	// delete element
	void del(T elem);

	// add elem in sorted order
	void add(T elem);
	


private:
	// inner class: list::node
	struct node {
		T elem; // list of int values
		struct node *next;
	};
	list::node *allocmem(T elem);
	void freemem(list::node *ptr);


	list::node *head; /* list head ptr */
};

#endif /* _LISTAPI_HPP_INCLUDED_ */
