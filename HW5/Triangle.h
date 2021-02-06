//============================================================================
// Name        : Triangle.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include "Shape.h"

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;
//Class for Triangle of Shape in ComposeShape
namespace shape
{
class Triangle : public Shape
{
	//public members
  public:
	//constructer initialize
	Triangle();
	Triangle(string color, double length);
	Triangle(double posX, double posY, double point1X, double point1Y,
			 double point2X, double point2Y, double point3X, double point3Y,
			 string color, double rotateAngle, double rotateX, double rotateY,
			 double length);

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version

	const Triangle operator-(const double size) const; //subtract this double to the size of the shape to make the new shape
	const Triangle operator+(const double size) const; //add this double to the size of the shape to make the new shape

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Triangle &obj);

	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

	//get set and public function prototype
	string getColor() const;
	void setColor(string color);
	double getPoint1X() const;
	void setPoint1X(double point1X) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPoint1Y() const;
	void setPoint1Y(double point1Y) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPoint2X() const;
	void setPoint2X(double point2X) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPoint2Y() const;
	void setPoint2Y(double point2Y) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPoint3X() const;
	void setPoint3X(double point3X) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPoint3Y() const;
	void setPoint3Y(double point3Y) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPosX() const;
	void setPosX(double posx) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPosY() const;
	void setPosY(double posy) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateX() const;
	void setRotateX(double rotateX) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateY() const;
	void setRotateY(double rotateY) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getLength() const;
	void setLength(double length) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11

	//static functions
	static double getTotalAreas();
	static double getTotalPerimeters();

	static void setTotalAreas(double totalAreas);
	static void setTotalPerimeters(double totalPerimeters);

	//private members
  private:
	static double _totalAreas;
	static double _totalPerimeters;

	double _posX;
	double _posY;
	double _point1X;
	double _point1Y;
	double _point2X;
	double _point2Y;
	double _point3X;
	double _point3Y;
	string _color;
	double _rotateAngle;
	double _rotateX;
	double _rotateY;
	double _length;
};
} // namespace shape
#endif /* TRIANGLE_H_ */
