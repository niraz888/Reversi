/*
 * Point.h
 *
 * natan furer 204594428
 * 
 */

#ifndef POINT_H_
#define POINT_H_
using namespace std;
#include <iostream>

class Point {
public:

	/**
	 * Point function - creates a point with the given values.
	 * @param x - x value.
	 * @param y - y value.
	 *
	 */
	Point(int x, int y);

    /**
	 * Point function - creates a point with default value (0,0).
	 *
	 */
	Point();

	/**
	 * getY function - returns the y value of the current point.
	 *
	 * @return y value.
	 */
	int getY() const;


	/**
	 * getX function - returns the x value of the current point.
	 *
	 */
	int getX() const;

	/**
	 * setX function - sets the x value of the current point.
	 *
	 * @param xV - x value.
	 * @return y value.
	 */
	void setX(int xV);

	/**
	 * setY function - sets the Y value of the current point.
	 *
	 * @param xV - x value.
	 */
	void setY(int xV);

	/**
	 * setPoint function - sets the point with the given values.
	 *
	 * @param x - x value.
	 * @param y - y value.
	 */
	void setPoint(int x, int y);

	/**
	 * operator == function - overload the operator == to compare two
	 * points(current with given).
	 *
	 * @param p - point to compare.
	 */
	bool operator ==(const Point &p) const;

	/**
	 * operator << function - overload the operator << to print the given point
	 * in the format- (x,y).
	 *
	 * @param out.
	 * @param p - point to print.
	 */
	friend ostream &operator <<(ostream &out, const Point &p);

private:
	int x;
	int y;
};

#endif /* POINT_H_ */
