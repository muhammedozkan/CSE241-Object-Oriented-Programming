//============================================================================
// Name        : PolygonVect.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "PolygonVect.h"
//Class for PolygonVect of Shape in ComposeShape
namespace shape
{
PolygonVect::PolygonVect()
{
}

//constructer ex: PolygonVect(Rectangle)
PolygonVect::PolygonVect(Rectangle &rect)
{ //assign class member value
	setPointCount(4);
	setColor(rect.getColor());
	setRotateAngle(rect.getRotateAngle());
	setRotateX(rect.getRotateX());
	setRotateY(rect.getRotateY());

	Point2D p1(rect.getPosX() + rect.getX(), rect.getPosY() + rect.getY());
	_vect2D.push_back(p1);

	Point2D p2(rect.getPosX() + rect.getX(), rect.getPosY() + rect.getHeight() + rect.getY());
	_vect2D.push_back(p2);

	Point2D p3(rect.getPosX() + rect.getWidth() + rect.getX(), rect.getPosY() + rect.getHeight() + rect.getY());
	_vect2D.push_back(p3);

	Point2D p4(rect.getPosX() + rect.getWidth() + rect.getX(), rect.getPosY() + rect.getY());
	_vect2D.push_back(p4);

	setArea(rect.area());
	setPerimeter(rect.perimeter());
}

//constructer ex: PolygonVect(Circle)
PolygonVect::PolygonVect(Circle &circ)
{					//assign class member value
	int side = 100; //circle represented side value 100 default value
	setPointCount(side);
	setColor(circ.getColor());
	setRotateAngle(circ.getRotateAngle());
	setRotateX(circ.getRotateX());
	setRotateY(circ.getRotateY());

	double angle = 2 * M_PI / side;

	for (int i = 0; i < side; ++i)
	{
		Point2D p(circ.getPosX() + circ.getRadius() * cos(angle * i), circ.getPosY() - circ.getRadius() * sin(angle * i));
		_vect2D.push_back(p);
	}

	setArea(circ.area());
	setPerimeter(circ.perimeter());
}

//reference PolygonVect [] operator overloading
PolygonVect::Point2D &PolygonVect::operator[](int index) throw(out_of_range) //dynamic exception specifications are deprecated in C++11 //lvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return _vect2D.at(index);
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//reference PolygonVect [] operator overloading
const PolygonVect::Point2D &PolygonVect::operator[](int index) const throw(out_of_range) //dynamic exception specifications are deprecated in C++11 //rvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return _vect2D.at(index);
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//constructer ex: PolygonVect(Triangle)
PolygonVect::PolygonVect(Triangle &trig)
{ //assign class member value
	setPointCount(3);
	setColor(trig.getColor());
	setRotateAngle(trig.getRotateAngle());
	setRotateX(trig.getRotateX());
	setRotateY(trig.getRotateY());

	Point2D p1(trig.getPoint1X() + trig.getPosX(), trig.getPoint1Y() + trig.getPosY());
	_vect2D.push_back(p1);

	Point2D p2(trig.getPoint2X() + trig.getPosX(), trig.getPoint2Y() + trig.getPosY());
	_vect2D.push_back(p2);

	Point2D p3(trig.getPoint3X() + trig.getPosX(), trig.getPoint3Y() + trig.getPosY());
	_vect2D.push_back(p3);

	setArea(trig.area());
	setPerimeter(trig.perimeter());
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, PolygonVect &obj)
{
	outs << "<polygon points=\"";
	for (int i = 0; i < obj.getPointCount(); ++i)
	{
		outs << obj[i].getX() << "," << obj[i].getY();
		if (i + 1 < obj.getPointCount())
		{
			outs << " ";
		}
	}

	outs << "\" transform=\"rotate(" << obj.getRotateAngle() << " " << obj.getRotateX()
		 << " " << obj.getRotateY() << ")\" fill=\"" << obj.getColor()
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;

	return outs;
}

ostream &PolygonVect::draw(ostream &outs)
{
	outs << *this;
	return outs;
}

//Prefix version
Shape &PolygonVect::operator++()
{
	for (int i = 0; i < getPointCount(); ++i)
	{
		(*this)[i].setX((*this)[i].getX() + 1.0);
		(*this)[i].setY((*this)[i].getY() + 1.0);
	}

	Shape *shp = new PolygonVect(*this);

	return *shp;
}

//Postfix version
Shape &PolygonVect::operator++(int ignoreMe)
{
	double tempPosX, tempPosY;

	Shape *shp = new PolygonVect(*this);
	for (int i = 0; i < getPointCount(); ++i)
	{
		tempPosX = (*this)[i].getX();
		tempPosY = (*this)[i].getY();
		tempPosX += 1.0;
		tempPosY += 1.0;
		(*this)[i].setX(tempPosX);
		(*this)[i].setY(tempPosY);
	}
	return *shp;
}

//Prefix version
Shape &PolygonVect::operator--()
{
	for (int i = 0; i < getPointCount(); ++i)
	{
		(*this)[i].setX((*this)[i].getX() - 1.0);
		(*this)[i].setY((*this)[i].getY() - 1.0);
	}

	Shape *shp = new PolygonVect(*this);

	return *shp;
}

//Postfix version
Shape &PolygonVect::operator--(int ignoreMe)
{
	double tempPosX, tempPosY;

	Shape *shp = new PolygonVect(*this);
	for (int i = 0; i < getPointCount(); ++i)
	{
		tempPosX = (*this)[i].getX();
		tempPosY = (*this)[i].getY();
		tempPosX -= 1.0;
		tempPosY -= 1.0;
		(*this)[i].setX(tempPosX);
		(*this)[i].setY(tempPosY);
	}
	return *shp;
}

//area calculating
double PolygonVect::area()
{
	return (getArea());
}

//perimeter calculating
double PolygonVect::perimeter()
{
	return (getPerimeter());
}

//operator overloading +
PolygonVect operator+(PolygonVect &firstOperand, PolygonVect &secondOperand)
{
	int pointCount = firstOperand.getPointCount() + secondOperand.getPointCount();
	PolygonVect out;
	out.setPointCount(pointCount);
	out.setColor("white");
	out.setRotateAngle(0);
	out.setRotateX(0);
	out.setRotateY(0);
	int i;

	for (i = 0; i < firstOperand.getPointCount(); ++i)
	{
		out[i].setX(firstOperand[i].getX());
		out[i].setY(firstOperand[i].getY());
	}

	for (int j = 0; j < secondOperand.getPointCount(); ++j, ++i)
	{
		out[i].setX(secondOperand[j].getX());
		out[i].setY(secondOperand[j].getY());
	}

	return out;
}

//Operators == comparison operators to compare two PolygonVect operator overloading
bool operator==(PolygonVect &firstOperand, PolygonVect &secondOperand)
{
	if (firstOperand.getPointCount() == secondOperand.getPointCount())
	{
		for (int i = 0; i < firstOperand.getPointCount(); ++i)
		{
			if (!(firstOperand[i].getX() == secondOperand[i].getX() && firstOperand[i].getY() == secondOperand[i].getY()))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//constructer ex: PolygonVect(Point2D)
PolygonVect::PolygonVect(Point2D &point2d)
{ //assign class member value
	setPointCount(1);
	setColor("white");
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);

	_vect2D.push_back(point2d);

	setArea(0);
	setPerimeter(0);
}

//constructer ex: PolygonVect(vector<Point2D>)
PolygonVect::PolygonVect(vector<Point2D> &vectPoint)
{ //assign class member value
	setPointCount(vectPoint.size());
	setColor("white");
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);

	for (int i = 0; i < getPointCount(); ++i)
	{
		_vect2D.push_back(vectPoint[i]);
	}

	setArea(0);		 // not calculated
	setPerimeter(0); // not calculated
}

} // namespace shape