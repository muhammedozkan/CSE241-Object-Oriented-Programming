//============================================================================
// Name        : ArrayList.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "ArrayList.h"

namespace GTU
{ //Implements List functions
template <typename E>
ArrayList<E>::ArrayList()
{
}

template <typename E>
bool ArrayList<E>::add(E e)
{
    _c.push_back(e);
    _c.sort();
    return true;
}

template <typename E>
bool ArrayList<E>::addAll(list<E> &c)
{
    for (auto o : c)
    {
        add(o);
    }

    return true;
}

template <typename E>
bool ArrayList<E>::contains(E e)
{
    for (auto o : _c)
    {
        if (o == e)
        {
            return true;
        }
    }
    return false;
}

template <typename E>
bool ArrayList<E>::containsAll(list<E> &c)
{
    for (auto o : c)
    {
        if (contains(o) == false)
        {
            return false;
        }
    }
    return true;
}

template <typename E>
bool ArrayList<E>::remove(E e)
{
    _c.remove(e);
    return true;
}

template <typename E>
bool ArrayList<E>::removeAll(list<E> &c)
{
    for (auto o : c)
    {
        remove(o);
    }
    return true;
}

template <typename E>
bool ArrayList<E>::retainAll(list<E> &c)
{
    int flag = 0;

    for (auto o : _c)
    {
        flag = 0;
        for (auto v : c)
        {
            if (o == v)
                flag = 1;
        }
        if (flag == 0)
            remove(o);
    }
    return true;
}

template <typename E>
bool ArrayList<E>::isEmpty()
{
    return _c.empty();
}

template <typename E>
int ArrayList<E>::size()
{
    return _c.size();
}

template <typename E>
void ArrayList<E>::clear()
{
    _c.clear();
}

template <typename E>
typename list<E>::iterator ArrayList<E>::iterator()
{
    return _c.begin();
}
} // namespace GTU
