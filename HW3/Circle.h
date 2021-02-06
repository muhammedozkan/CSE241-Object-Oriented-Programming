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

#ifndef CIRCLE_H_
#define CIRCLE_H_
//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for Circle of Shape in ComposeShape
class Circle
{
	//public members
  public:
	//constructer initialize
	Circle();
	Circle(string color, double radius);
	Circle(double posX, double posY, double radius, string color,
		   double rotateAngle, double rotateX, double rotateY);

	//operator overloading
	Circle operator++();	//Prefix version
	Circle operator++(int); //Postfix version

	Circle operator--();	//Prefix version
	Circle operator--(int); //Postfix version

	const Circle operator-(const double size) const; //subtract this double to the size of the shape to make the new shape
	const Circle operator+(const double size) const; //add this double to the size of the shape to make the new shape

	//Operators == , !=, and other comparison operators to compare two shape operator overloading
	bool operator==(Circle &secondOperand)
	{
		return (area() == secondOperand.area());
	}
	bool operator!=(Circle &secondOperand)
	{
		return (area() != secondOperand.area());
	}
	bool operator<=(Circle &secondOperand)
	{
		return (area() <= secondOperand.area());
	}
	bool operator>=(Circle &secondOperand)
	{
		return (area() >= secondOperand.area());
	}
	bool operator<(Circle &secondOperand)
	{
		return (area() < secondOperand.area());
	}
	bool operator>(Circle &secondOperand)
	{
		return (area() > secondOperand.area());
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Circle &obj);

	double area();
	double perimeter();

	//get set and public function prototype

	string getColor() const;
	void setColor(string color);
	double getPosX() const;
	void setPosX(double posX);
	double getPosY() const;
	void setPosY(double posY);
	double getRadius() const;
	void setRadius(double radius);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);

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

#endif /* CIRCLE_H_ */
