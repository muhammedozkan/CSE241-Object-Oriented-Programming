//============================================================================
// Name        : Collection.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <iterator>

#ifndef COLLECTION_H_
#define COLLECTION_H_

using namespace std;

namespace GTU
{ //This is a templated class with two template parameters like the std::stack class of STL. The
//first parameter is the template type E and the second parameter is the STL container that will
//do all the work for us.
template <typename E, typename Container = vector<E>>
class Collection
{

	//protected members
  protected:
	//public members
  public: //pure virtual abstract functions
	virtual bool add(E e) = 0;
	virtual bool addAll(Container &c) = 0;
	virtual bool contains(E e) = 0;
	virtual bool containsAll(Container &c) = 0;
	virtual bool remove(E e) = 0;
	virtual bool removeAll(Container &c) = 0;
	virtual bool retainAll(Container &c) = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;
};

} // namespace GTU
#endif /* COLLECTION_H_ */