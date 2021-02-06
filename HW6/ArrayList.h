//============================================================================
// Name        : ArrayList.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <list>
#include "Iterator.h"
#include "List.h"

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

using namespace std;

namespace GTU
{
template <typename E>
class ArrayList : public List<E>
{
  //public members
public:
  ArrayList();

  virtual bool add(E e);                         //Ensures that this collection contains the specified element
  virtual bool addAll(list<E> &c);               //Adds all of the elements in the specified collection to this collection
  virtual bool contains(E e);                    //Returns true if this collection contains the specified element.
  virtual bool containsAll(list<E> &c);          //Returns true if this collection contains all of the elements in the specified collection.
  virtual bool remove(E e);                      //Removes a single instance of the specified element from this collection, if it is present
  virtual bool removeAll(list<E> &c);            //Removes all of this collection's elements that are also contained in the specified collection
  virtual bool retainAll(list<E> &c);            //Retains only the elements in this collection that are contained in the specified collection
  virtual bool isEmpty();                        //Returns true if this collection contains no elements.
  virtual int size();                            //Returns the number of elements in this collection.
  virtual void clear();                          //Removes all of the elements from this collection
  virtual typename list<E>::iterator iterator(); //Returns an iterator over the collection

  //private members
private:
  list<E> _c;
};

} // namespace GTU
#endif /* ARRAYLIST_H_ */