#include <iostream>
#include "points2d.h"
#include <random>
#include <algorithm>

void test1()
{
	std::cout <<"Running test 1\n";
	std::random_device rnd_dev;
	std::mt19937 rnd_generator(rnd_dev());
	std::uniform_int_distribution<int> uniform_int_dis(100, 200); 
	int i_num = uniform_int_dis(rnd_generator);
	
	Points2D points[10];
	for(int i = 0; i < 10; ++i) {
		int x = uniform_int_dis(rnd_generator);
		int y = uniform_int_dis(rnd_generator);
		std::cout << x << " and " << y << std::endl;
#if 0
		Points2D p(x,y); // create objevt using ctor that takes x,y
		points[i] = p;
#endif
		points[i] = Points2D(x,y); // create and assign points object
	}
	
	for(int i = 0; i < 10; ++i) {
		points[i].print();
	}
	
	for(int i = 0; i < 10; ++i) {
		std::cout << points[i];
	}	
}

void
test2() {
	std::cout << "Running Test 2 \n";
	std::random_device rnd_dev;
	std::mt19937 rnd_generator(rnd_dev());
	std::uniform_int_distribution<int> uniform_int_dis(10, 20); 
	
	Points2D points[10];  // created using default ctor
	for (int i = 0; i < 10; ++i) {
		int x = uniform_int_dis(rnd_generator);
		int y = uniform_int_dis(rnd_generator);
		points[i] = Points2D(x,y);
	}
	for(int i = 0; i < 0; ++i) {
		points[i].print();
		std::cout << points[i];
	}

	std::sort(std::begin(points), std::end(points));
	std::cout << "sorted points \n";
	for(int i = 0; i < 0; ++i) {
		points[i].print();
		std::cout << points[i];
	}
#if 0	
	// sort using lambda (anonymous function)
	std::sort(std::begin(points), std::end(points), [](const Points2D& p1, const Points2D &p2)
	{
		if(p1.getY() < p2.getY()) 
			return true;
		return false;
	});
	std::cout << "sorted points by y \n";
	for(int i = 0; i < 0; ++i) {
		points[i].print();
		std::cout << points[i];
	}
#endif
	std::sort(std::begin(points), std::end(points), sortbyycoord());
	std::cout << "sorted points by y coord \n";
	for(int i = 0; i < 0; ++i) {
		points[i].print();
		std::cout << points[i];
	}
}

int
main(int argc, char ** argv) {
	Points2D p1; //create an object using default constructor
	Points2D p3;
	p3 = p1;

	Points2D *p2 = new Points2D;

	test1();
	test2();

	return 0;
}
