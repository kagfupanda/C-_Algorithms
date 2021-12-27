#ifndef _POINTS2D_H_INCLUDED_
#define _POINTS2D_H_INCLUDED_

/* Define an object for 2D Point coordinates */
class Points2D {
public:
	Points2D(); /* default ctor */
	Points2D(int x1, int y1); // Create object with x1, y1 values for coords */
	~Points2D(); /* dtor */
	Points2D(const Points2D &that); /* copy constructor: copy that into this */
	Points2D& operator = (const Points2D &that); /* Assignment operator */
	friend std::ostream& operator<<(std::ostream& os, const Points2D& point); /* print operator */
	void print(); /* print point to stdout: std::cout */
	//define operator < for compare
	bool operator<(const Points2D &that);
	// getter methods
	int getX() const { return x; }
	int getY() const { return y; }

private:
	/* x, y coordinates */
	int x;
	int y;
};

struct sortbyycoord { // sortbycoord functor object: object used as a function
	bool operator()(const Points2D& p1, const Points2D &p2) {
		if(p1.getY() < p2.getY())
			return true;
		return false;
	}
};

#endif /* _POINTS2D_H_INCLUDED_ */


