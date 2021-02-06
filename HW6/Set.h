//============================================================================
// Name        : Set.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <set>
#include <iterator>
#include "Collection.h"

#ifndef SET_H_
#define SET_H_

using namespace std;

namespace GTU
{
template <typename E>
class Set : public Collection<E, set<E>>
{		  //A collection that contains no duplicate elements. There is no order for this collection. In other words, you don’t have to keep the insertion order of the elements.
		  //public members
  public: //pure virtual abstract functions
	virtual bool add(E e) = 0;
	virtual bool addAll(set<E> &c) = 0;
	virtual bool contains(E e) = 0;
	virtual bool containsAll(set<E> &c) = 0;
	virtual bool remove(E e) = 0;
	virtual bool removeAll(set<E> &c) = 0;
	virtual bool retainAll(set<E> &c) = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;

	//private members
  private:
};

} // namespace GTU
#endif /* SET_H_ */