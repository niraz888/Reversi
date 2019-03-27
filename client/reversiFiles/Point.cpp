/*
 * Point.cpp
 *
 *  natan furer 204594428
 */

#include "Point.h"
using namespace std;

Point::Point(int xValue, int yValue): x(xValue), y(yValue) {}

Point::Point() {
	x = 0;
	y = 0;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setY(int yV) {
	y = yV;
}

void Point::setX(int xV) {
	x = xV;
}
void Point::setPoint(int xV, int yV) {
	x = xV;
	y = yV;
}

bool Point::operator ==(const Point &p) const {
	if(x == p.getX() && y == p.getY()) {
		return true;
	}
	return false;
}

ostream &operator <<(ostream &out, const Point &p) {
	out << "(" << p.getX()  << "," << p.getY()<< ")";
	return out;
}



