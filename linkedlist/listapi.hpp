#include <iostream>

/* using global namespace */

// A 'class' is same as 'stuct' EXCEPT;
// by default all members of 'class' private but in struct they are public
class list {
public:
	// constructor (init)
	list(); 
	// destructor (dtor)
	~list(); 
	
	// insert elem at the beginning
	void insert(int elem);
	
	// append elemt at the end
	void append(int elem);
	
	//print list to stdout
	void print();
	
	// find element
	bool find(int elem);

	// delete element
	void del(int elem);

	// add elem in sorted order
	void add(int elem);
	


private:
	// inner class: list::node
	struct node {
		int elem; // list of int values
		struct node *next;
	};
	list::node *allocmem(int elem);
	void freemem(list::node *ptr);


	list::node *head; /* list head ptr */
};
