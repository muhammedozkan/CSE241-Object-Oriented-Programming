//============================================================================
// Name        : PolygonVect.h
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

#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_

//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for PolygonVect of Shape in ComposeShape
namespace shape
{
class PolygonVect : public Polygon
{
	//public members
  public:
	//constructer initialize
	PolygonVect();
	PolygonVect(vector<Point2D> &vectPoint);
	PolygonVect(Rectangle &rect);
	PolygonVect(Circle &circ);
	PolygonVect(Triangle &trig);
	PolygonVect(Point2D &point2d);

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version

	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

	//Operators == , !=, and + operators two PolygonVect operator overloading
	friend PolygonVect operator+(PolygonVect &firstOperand, PolygonVect &secondOperand);
	friend bool operator==(PolygonVect &firstOperand, PolygonVect &secondOperand);
	friend bool operator!=(PolygonVect &firstOperand, PolygonVect &secondOperand)
	{
		return !(firstOperand == secondOperand);
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, PolygonVect &obj);

	Point2D &operator[](int index) throw(out_of_range);				//dynamic exception specifications are deprecated in C++11  //lvalue
	const Point2D &operator[](int index) const throw(out_of_range); //dynamic exception specifications are deprecated in C++11  //rvalue

	//private members
  private:
	vector<Point2D> _vect2D; //vector defition
};
} // namespace shape
#endif /* POLYGONVECT_H_ */