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

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std;
//Class for Rectangle of Shape in ComposeShape
class Rectangle
{
	//public members
  public:
	//constructer initialize
	Rectangle();
	Rectangle(string color, double height, double width);
	Rectangle(double posX, double posY, double width, double height,
			  string color, double rotateAngle, double rotateX, double rotateY,
			  double x, double y);

	//operator overloading
	Rectangle operator++();	//Prefix version
	Rectangle operator++(int); //Postfix version

	Rectangle operator--();	//Prefix version
	Rectangle operator--(int); //Postfix version

	const Rectangle operator-(const double size) const; //subtract this double to the size of the shape to make the new shape
	const Rectangle operator+(const double size) const; //add this double to the size of the shape to make the new shape

	//Operators == , !=, and other comparison operators to compare two shape operator overloading
	bool operator==(Rectangle &secondOperand)
	{
		return (area() == secondOperand.area());
	}
	bool operator!=(Rectangle &secondOperand)
	{
		return (area() != secondOperand.area());
	}
	bool operator<=(Rectangle &secondOperand)
	{
		return (area() <= secondOperand.area());
	}
	bool operator>=(Rectangle &secondOperand)
	{
		return (area() >= secondOperand.area());
	}
	bool operator<(Rectangle &secondOperand)
	{
		return (area() < secondOperand.area());
	}
	bool operator>(Rectangle &secondOperand)
	{
		return (area() > secondOperand.area());
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Rectangle &obj);

	double area();
	double perimeter();

	//get set and public function prototype
	string getColor() const;
	void setColor(string color);
	double getHeight() const;
	void setHeight(double height);
	double getPosX() const;
	void setPosX(double posX);
	double getPosY() const;
	void setPosY(double posY);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);
	double getWidth() const;
	void setWidth(double width);
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

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

#endif /* RECTANGLE_H_ */
