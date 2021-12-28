#include <iostream>
#include <array>
#include "rbtree.h"
#include <iterator>

int
main(int argc, char **argv) {
	RBTree *rbtree1 = new RBTree();
	
	std::array<Key_t, 10> keyChars = {'B', 'D', 'W', 'Z', 'J', 'D', 'C', 'O', 'L', 'F'};
	std::array<Value_t, 10> valChars = {'B', 'D', 'W', 'Z', 'J', 'D', 'C', 'O', 'S', 'F'};
	
	std::array<Key_t, 10>::iterator k_iter; // iterator is a pointer (so derefence it to get its value)
	std::array<Value_t, 10>::iterator v_iter;
	for(k_iter = keyChars.begin(), v_iter = valChars.begin(); k_iter < keyChars.end(); ++k_iter, ++v_iter) {
		std::cout << "call put: "
		<< "key: " << k_iter
		<< "value: " << *v_iter
		<< std::endl;
		rbtree1->put(*k_iter, *v_iter);
		std::cout << "Tree size: " << rbtree1->size() << std::endl;
	}

	rbtree1->print();
{
	std::cout << "Test Floor of N \n";
	Key_t floor_k = rbtree1->floor('N');
	if(floor_k == NULL) {
		std::cout << "NULL is floor \n";
	} else {
	std::cout << "Floor of N is : " << floor_k << std::endl;
	}
}
{
	std::cout << "Test Floor of N \n";
	Key_t floor_k = rbtree1->floor('A');
	if(floor_k == NULL) {
		std::cout << "NULL is floor \n";
	} else {
	std::cout << "Floor of A is : " << floor_k << std::endl;
	}
}
	std::cout <<"Rank of L\n";
	int r = rbtree1->rank('L');
	std::cout << "rank: " << r << std::endl;

	std::cout << "Test deletemin \n";
	rbtree1->deleteMin();
	rbtree1->print();
	std::cout << "Tree size: " << rbtree1->size() << std::endl;
	rbtree1->deleteMin();
	rbtree1->print();
	std::cout << "Tree size: " << rbtree1->size() << std::endl;


	return 0;
}
