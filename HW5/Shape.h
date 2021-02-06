//============================================================================
// Name        : Shape.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>

#ifndef SHAPE_H_
#define SHAPE_H_

using namespace std;
//Abstract Class for Shapes
namespace shape
{

class Shape
{
	//public members
  public:
	//constructer initialize

	virtual double area() = 0;				  //pure virtual function
	virtual double perimeter() = 0;			  //pure virtual function
	virtual ostream &draw(ostream &outs) = 0; //pure virtual function

	//operator overloading
	virtual Shape &operator++() = 0;	//Prefix version
	virtual Shape &operator++(int) = 0; //Postfix version
	virtual Shape &operator--() = 0;	//Prefix version
	virtual Shape &operator--(int) = 0; //Postfix version

	//Operators == , !=, and other comparison operators to compare two shape operator overloading
	virtual bool operator==(Shape &secondOperand) final
	{
		return (area() == secondOperand.area());
	}
	virtual bool operator!=(Shape &secondOperand) final
	{
		return (area() != secondOperand.area());
	}
	virtual bool operator<=(Shape &secondOperand) final
	{
		return (area() <= secondOperand.area());
	}
	virtual bool operator>=(Shape &secondOperand) final
	{
		return (area() >= secondOperand.area());
	}
	virtual bool operator<(Shape &secondOperand) final
	{
		return (area() < secondOperand.area());
	}
	virtual bool operator>(Shape &secondOperand) final
	{
		return (area() > secondOperand.area());
	}

	//private members
  private:
};

//get reference ostream parameter global operator overloading
ostream &operator<<(ostream &outs, Shape *obj); //Overloaded global operator<< can be used for printing the shapes to SVG files.

} // namespace shape
#endif /* SHAPE_H_ */