#include <iostream>
#include "listapi.hpp"

void 
test3()
{
	std::cout << "Running test3 \n";
	list *list1 = new list();
	
	for (int i = 0; i < 10; ++i) {
		list1->add(i);
	}
	list1->print();
	
	for(int i = 100; i < 110; ++i) {
		list1->add(i);
	}

	for(int i = 50; i < 60; ++i) {
		list1->add(i);
	}
	list1->print();
	
	delete list1;
}
void
test2() {
	std::cout << "Running Test 2 \n";
	list *list1 = new list();
	for (int i = 0; i < 10; ++i) {
		list1->insert(i);
	}
	list1->print();
	if(list1->find(3)) {
		std::cout <<"Found 3 in list" << std::endl;
	} 
	if (list1->find(30)) {
		std::cout <<"Found 30 in list" << std::endl;	
	} else {
		std::cout <<"NOT Found 30 in list" << std::endl;	
	}

	list1->del(3);
	list1->print();
	if(list1->find(3)) {
		std::cout <<"Found 3 in list" << std::endl;
	} else {
		std::cout <<"NOT Found 3 in list" << std::endl;
	}
	delete list1;
}

void
test1()
{
	std::cout << "Runnig Test1 \n";
	list *list1 = new list();
	for (int i = 0; i < 10; ++i) {
		list1->insert(i);
	}
	list1->print();
	delete list1;	

	list *list2 = new list();
	for(int i = 0; i< 10; ++i) {
		list2->append(i);
	}
	list2->print();
	delete list2;
}

int main(int argc, char **argv) {
	list *list1 = new list();
	delete list1;

	test1();

	test2();

	test3();
	return 0;
}
