#include <iostream>

#include "points2d.h" // API to object

Points2D::Points2D() { //default ctor
	/* Initizlize data members */
	x = 0;
	y = 0;
}

Points2D::Points2D(int x1, int y1) { // ctor
	x = x1;
	y = y1;
}

Points2D::~Points2D() { //dtor
	// Nothing
	std::cerr << "enter: points2d dtor called \n"; }

Points2D::Points2D(const Points2D &that) {
	// copy over data members
	this->x = that.x;
	this->y = that.y;
}

Points2D&
Points2D::operator = (const Points2D &that) { /* Assignment operator */
	std::cout<< "enter :  operator = \n";
	// do not assign over self
	if(this != &that) {	
		// copy data member
		this->x = that.x;
		this->y = that.y;
	}
	std::cout << "return: operator = \n";
	return *this; //derefence and return reference to self object
}
#if 0
struct sortbyycoord { // sortbycoord functor object: object used as a function
	bool operator()(const Points2D& p1, const Points2D &p2) {
		if(p1.y < p2.y)
			return true;
		return false;
	}
};
#endif
std::ostream& operator<<(std::ostream& os, const Points2D& point) { /* print operator */
	os << point.x << "," << point.y << std::endl;
	return os;
}
void
Points2D::print() { /* print point to stdout: std::cout */
	std::cout << this->x << "," << this->y << std::endl;
}

bool
Points2D:: operator<(const Points2D &other) {
	if(this->x < other.x)
		return true;
	return false;
}

