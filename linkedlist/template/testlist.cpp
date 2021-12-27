#include <iostream>
#include "listapi.hpp"
#include "listimpl.cpp"

void test4() {
	std::cout << "Running test4 \n";
	
	list<int> *list1 = new list<int>();
	list<double> *list2 = new list<double>();
	
	for (int i =0; i < 10; ++i) {
		list1->add(i);
		list2->add(i * 1.1);
	}
	list1->print();
	list2->print();
	
	delete list1; // free up memory
	delete list2; // free up memory
}

void 
test3()
{
	std::cout << "Running test3 \n";
	list<int> *list1 = new list<int>();
	
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
	list<int> *list1 = new list<int>();
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
	list<int> *list1 = new list<int>();
	for (int i = 0; i < 10; ++i) {
		list1->insert(i);
	}
	list1->print();
	
	list<int> *list2 = new list<int>();
	for(int i = 0; i< 10; ++i) {
		list2->append(i);
	}
	list2->print();
	
	delete list1;
	delete list2;
}

int main(int argc, char **argv) {
	list<int> *list1 = new list<int>();
	delete list1;

	test1();

	test2();

	test3();
	
	test4();
	return 0;
}
