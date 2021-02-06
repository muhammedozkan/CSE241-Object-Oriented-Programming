//============================================================================
// Name        : Iterator.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Iterator.h"

namespace GTU
{

template <typename T>
Iterator<T>::Iterator()
{
    itr = nullptr;
}

template <typename T>
Iterator<T>::Iterator(const Iterator &other)
{
    itr = other.itr;
}

template <typename T>
Iterator<T>::~Iterator()
{
    itr = nullptr;
}

template <typename T>
T &Iterator<T>::next() const
{
    return *itr;
}

template <typename T>
bool Iterator<T>::hasNext()
{
    return (((T)*itr).begin());
}

template <typename T>
void Iterator<T>::remove()
{
    ((T)*itr).clear(); //throw
}

} // namespace GTU
