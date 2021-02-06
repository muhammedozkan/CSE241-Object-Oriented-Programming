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

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;
//Class for Triangle of Shape in ComposeShape
class Triangle
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
	//get set and public function prototype
	void draw(ofstream &file); //get reference ofstream parameter
	double area();
	string getColor() const;
	void setColor(string color);
	double getPoint1X() const;
	void setPoint1X(double point1X);
	double getPoint1Y() const;
	void setPoint1Y(double point1Y);
	double getPoint2X() const;
	void setPoint2X(double point2X);
	double getPoint2Y() const;
	void setPoint2Y(double point2Y);
	double getPoint3X() const;
	void setPoint3X(double point3X);
	double getPoint3Y() const;
	void setPoint3Y(double point3Y);
	double getPosX() const;
	void setPosX(double posx);
	double getPosY() const;
	void setPosY(double posy);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);
	double getLength() const;
	void setLength(double length);
	//private members
  private:
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

#endif /* TRIANGLE_H_ */
