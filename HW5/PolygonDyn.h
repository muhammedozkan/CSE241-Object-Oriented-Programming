//============================================================================
// Name        : PolygonDyn.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include "Polygon.h"

#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for PolygonDyn of Shape in ComposeShape
namespace shape
{
class PolygonDyn : public Polygon
{
	//public members
  public:
	//constructer initialize
	PolygonDyn();
	PolygonDyn(vector<Point2D> &vectPoint);
	PolygonDyn(Rectangle &rect);
	PolygonDyn(Circle &circ);
	PolygonDyn(Triangle &trig);
	PolygonDyn(Point2D &point2d);

	//Big three
	PolygonDyn(const PolygonDyn &obj);
	PolygonDyn &operator=(const PolygonDyn &rightSide);
	virtual ~PolygonDyn();

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version

	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

	//Operators == , !=, and + operators two PolygonDyn operator overloading
	friend PolygonDyn operator+(PolygonDyn &firstOperand, PolygonDyn &secondOperand);
	friend bool operator==(PolygonDyn &firstOperand, PolygonDyn &secondOperand);
	friend bool operator!=(PolygonDyn &firstOperand, PolygonDyn &secondOperand)
	{
		return !(firstOperand == secondOperand);
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, PolygonDyn &obj);

	Point2D &operator[](int index) throw(out_of_range);				//dynamic exception specifications are deprecated in C++11 	//lvalue
	const Point2D &operator[](int index) const throw(out_of_range); //dynamic exception specifications are deprecated in C++11  //rvalue

	//private members
  private:
	Point2D *getPointsPtr() const;
	void setPointsPtr(Point2D *pointsPtr);

	Point2D *_pointsPtr; //array initial address
};
} // namespace shape
#endif /* POLYGONDYN_H_ */