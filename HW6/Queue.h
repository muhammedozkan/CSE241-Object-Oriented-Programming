//============================================================================
// Name        : Queue.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <vector>
#include <iterator>
#include "Collection.h"

#ifndef QUEUE_H_
#define QUEUE_H_

using namespace std;

namespace GTU
{ //Queues order elements in a FIFO (first-in-first-out) manner. There is no random access with this Collection. Some functions throw exceptions.
template <typename E>
class Queue : public Collection<E, vector<E>>
{
	//public members
  public: //pure virtual abstract functions
	virtual bool add(E e) = 0;
	virtual bool addAll(vector<E> &c) = 0;
	virtual bool contains(E e) = 0;
	virtual bool containsAll(vector<E> &c) = 0;
	virtual bool remove(E e) = 0;
	virtual bool removeAll(vector<E> &c) = 0;
	virtual bool retainAll(vector<E> &c) = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;

	//private members
  private:
};

} // namespace GTU
#endif /* QUEUE_H_ */