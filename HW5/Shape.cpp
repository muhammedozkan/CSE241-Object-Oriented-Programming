//============================================================================
// Name        : Shape.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Shape.h"
//Abstract Class for Shapes

namespace shape
{
//empty

ostream &operator<<(ostream &outs, Shape *obj) //only one shape draw
{
	obj->draw(outs); //polymorphism late binding
	return outs;
}

} // namespace shape
