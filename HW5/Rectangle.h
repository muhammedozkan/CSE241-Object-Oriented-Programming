//============================================================================
// Name        : Rectangle.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Shape.h"

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std;
//Class for Rectangle of Shape in ComposeShape
namespace shape
{
class Rectangle : public Shape
{
	//public members
  public:
	//constructer initialize
	Rectangle();
	Rectangle(string color, double height, double width);
	Rectangle(double posX, double posY, double width, double height,
			  string color, double rotateAngle, double rotateX, double rotateY,
			  double x, double y);

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version

	const Rectangle operator-(const double size) const; //subtract this double to the size of the shape to make the new shape
	const Rectangle operator+(const double size) const; //add this double to the size of the shape to make the new shape

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Rectangle &obj);

	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

	//get set and public function prototype
	string getColor() const;
	void setColor(string color);
	double getHeight() const;
	void setHeight(double height) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPosX() const;
	void setPosX(double posX) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getPosY() const;
	void setPosY(double posY) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateX() const;
	void setRotateX(double rotateX) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getRotateY() const;
	void setRotateY(double rotateY) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getWidth() const;
	void setWidth(double width) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getX() const;
	void setX(double x) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
	double getY() const;
	void setY(double y) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11

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
	double _width;
	double _height;
	string _color;
	double _rotateAngle;
	double _rotateX;
	double _rotateY;
	double _x;
	double _y;
};
} // namespace shape
#endif /* RECTANGLE_H_ */
