//============================================================================
// Name        : ComposedShape.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include "Polygon.h"
#include "Polyline.h"

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
using namespace shape;

class ComposedShape
{
	//public members
  public:
	//shapeElem inner class definition
	class ShapeElem
	{
		//public members
	  public:
		typedef enum class _shape_Type
		{
			Rectangle,
			Circle,
			Triangle
		} shapeType;

		//constructer initialize
		ShapeElem();
		ShapeElem(void *ptrShape, shapeType type);

		shapeType getType() const;
		void setType(shapeType type);

		void *getPtrShape();
		void setPtrShape(void *ptrShape);

		double getArea();
		double getPerimeter();

		//private members
	  private:
		shapeType _type;
		void *_ptrShape;
	};

	//constructer initialize
	ComposedShape();
	ComposedShape(Rectangle &mContainer, Rectangle &sShape);
	ComposedShape(Rectangle &mContainer, Circle &sShape);
	ComposedShape(Rectangle &mContainer, Triangle &sShape);
	ComposedShape(Circle &mContainer, Rectangle &sShape);
	ComposedShape(Circle &mContainer, Circle &sShape);
	ComposedShape(Circle &mContainer, Triangle &sShape);
	ComposedShape(Triangle &mContainer, Rectangle &sShape);
	ComposedShape(Triangle &mContainer, Circle &sShape);
	ComposedShape(Triangle &mContainer, Triangle &sShape);

	void optimalFit();

	//start Operators == , !=, and other comparison operators to compare two shapes operator overloading
	friend bool operator==(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Triangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}

	friend bool operator==(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Rectangle &firstOperand, Circle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}

	friend bool operator==(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Triangle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}

	friend bool operator==(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Circle &firstOperand, Rectangle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}

	friend bool operator==(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Rectangle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}

	friend bool operator==(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() == secondOperand.area());
	}
	friend bool operator!=(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() != secondOperand.area());
	}
	friend bool operator<=(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() <= secondOperand.area());
	}
	friend bool operator>=(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() >= secondOperand.area());
	}
	friend bool operator<(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() < secondOperand.area());
	}
	friend bool operator>(Circle &firstOperand, Triangle &secondOperand)
	{
		return (firstOperand.area() > secondOperand.area());
	}
	//end Operators == , !=, and other comparison operators to compare two shapes operator overloading

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, ComposedShape &obj);

	Polygon &operator[](int index);				//lvalue
	const Polygon &operator[](int index) const; //rvalue

	ComposedShape &operator+=(Polygon poly);

	vector<Polygon> &getPolygons();
	void setPolygons(vector<Polygon> polys);

	ShapeElem &getMainShape();
	ShapeElem &getSmallShape();

	static int svgOpen(string fileName, ofstream &svg);
	static int svgClose(ofstream &svg);

	//get set and public function prototype
	double getEmptyArea() const;
	void setEmptyArea(double emptyArea);
	int getObjectCount() const;
	void setObjectCount(int objectCount);
	string getMainColor() const;
	void setMainColor(string mainColor);

	//private members
  private:
	void optimalRectRect(Rectangle *mContainer, Rectangle *sShape);
	void optimalRectCirc(Rectangle *mContainer, Circle *sShape);
	void optimalRectTrig(Rectangle *mContainer, Triangle *sShape);
	void optimalCircRect(Circle *mContainer, Rectangle *sShape);
	void optimalCircCirc(Circle *mContainer, Circle *sShape);
	void optimalCircTrig(Circle *mContainer, Triangle *sShape);
	void optimalTrigRect(Triangle *mContainer, Rectangle *sShape);
	void optimalTrigCirc(Triangle *mContainer, Circle *sShape);
	void optimalTrigTrig(Triangle *mContainer, Triangle *sShape);

	ShapeElem _main;
	ShapeElem _shape;

	double _emptyArea;
	int _objectCount;
	string _mainColor;

	vector<Polygon> _polys;
};

#endif /* COMPOSEDSHAPE_H_ */
