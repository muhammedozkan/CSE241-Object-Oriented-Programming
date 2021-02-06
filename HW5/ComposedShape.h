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
#include <stdexcept>
#include <typeinfo>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include "PolygonDyn.h"
#include "PolygonVect.h"

#include "Shape.h"

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
using namespace shape;

ostream &printAll(ostream &outs, vector<Shape *> obj);  //Function printAll takes a vector of Shape pointers and prints all shapes to an SVG file
ostream &printPoly(ostream &outs, vector<Shape *> obj); //Function printPoly takes a vector of Shape pointers and prints all Polygon shapes to an SVG file
vector<Shape *> convertAll(vector<Shape *> obj);		//Function convertAll takes a vector of Shape pointers, converts all shapes to Polygons and returns a new vector with the new shapes.
void sortShapes(vector<Shape *> &obj);					//Function sortShapes takes a vector of Shape pointers and increasingly sorts them with respect to their areas.

class ComposedShape : public Shape
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

		double getArea() throw(invalid_argument);	  //dynamic exception specifications are deprecated in C++11
		double getPerimeter() throw(invalid_argument); //dynamic exception specifications are deprecated in C++11

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

	Shape *operator[](int index) throw(out_of_range);			  //dynamic exception specifications are deprecated in C++11 		  //lvalue
	const Shape *operator[](int index) const throw(out_of_range); //dynamic exception specifications are deprecated in C++11   //rvalue

	ComposedShape &operator+=(Shape *shp);
	//get reference ostream parameter global operator overloading
	friend ostream &operator<<(ostream &outs, ComposedShape &obj);
	vector<Shape *> getShapes();
	void setShapes(vector<Shape *> shp);

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

	virtual Shape &operator++() override;	//Prefix version
	virtual Shape &operator++(int) override; //Postfix version
	virtual Shape &operator--() override;	//Prefix version
	virtual Shape &operator--(int) override; //Postfix version
	virtual double area() override;
	virtual double perimeter() override;
	virtual ostream &draw(ostream &outs) override;

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

	vector<Shape *> _shp; //Class ComposedShape keeps a vector of Shape pointers for the shape elements.
};
#endif /* COMPOSEDSHAPE_H_ */