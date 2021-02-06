//============================================================================
// Name        : List.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <list>
#include <iterator>
#include "Collection.h"

#ifndef LIST_H_
#define LIST_H_

using namespace std;

namespace GTU
{
template <typename E>
class List : public Collection<E, list<E>>
{		  //An ordered collection (also known as a sequence). The user of this interface has precise control over where in the list each element is inserted.
		  //public members
  public: //pure virtual abstract functions
	virtual bool add(E e) = 0;
	virtual bool addAll(list<E> &c) = 0;
	virtual bool contains(E e) = 0;
	virtual bool containsAll(list<E> &c) = 0;
	virtual bool remove(E e) = 0;
	virtual bool removeAll(list<E> &c) = 0;
	virtual bool retainAll(list<E> &c) = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;

	//private members
  private:
};

} // namespace GTU
#endif /* LIST_H_ */