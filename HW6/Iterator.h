//============================================================================
// Name        : Iterator.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>

#ifndef ITERATOR_H_
#define ITERATOR_H_

using namespace std;

namespace GTU
{
template <typename T>
class Iterator
{
	//public members
  public:
	Iterator();
	Iterator(const Iterator &);
	~Iterator();
	T &next() const; //Returns true if the iteration has more elements.
	bool hasNext();  //Returns the next element in the iteration and advances the iterator.
	void remove();   //Removes from the underlying collection the last element returned by this iterator

	//private members
  private:
	T *itr;
};

} // namespace GTU
#endif /* ITERATOR_H_ */