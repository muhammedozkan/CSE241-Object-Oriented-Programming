//============================================================================
// Name        : Circle.h
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

#ifndef CIRCLE_H_
#define CIRCLE_H_
//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for Circle of Shape in ComposeShape
namespace shape
{
class Circle : public Shape
{
	//public members
  public:
	//constructer initialize
	Circle();
	Circle(string color, double radius);
	Circle(double posX, double posY, double radius, string color,
		   double rotateAngle, double rotateX, double rotateY);

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version

	const Circle operator-(const double size) const; //subtract this double to the size of the shape to make the new shape
	const Circle operator+(const double size) const; //add this double to the size of the shape to make the new shape

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Circle &obj);

	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

	//get set and public function prototype

	string getColor() const;
	void setColor(string color);
	double getPosX() const;
	void setPosX(double posX) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPosY() const;
	void setPosY(double posY) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRadius() const;
	void setRadius(double radius) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateX() const;
	void setRotateX(double rotateX) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateY() const;
	void setRotateY(double rotateY) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11

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
	double _radius;
	string _color;
	double _rotateAngle;
	double _rotateX;
	double _rotateY;
};
} // namespace shape
#endif /* CIRCLE_H_ */
