//============================================================================
// Name        : LinkedList.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "LinkedList.h"

namespace GTU
{ //Implements both List and Queue functions. Your class does not have to have a linked list to implement these.
template <typename E>
LinkedList<E>::LinkedList()
{
}

template <typename E>
bool LinkedList<E>::add(E e)
{
    _c.push_back(e);
    return true;
}

template <typename E>
bool LinkedList<E>::addAll(list<E> &c)
{
    for (auto o : c)
    {
        add(o);
    }

    return true;
}

template <typename E>
bool LinkedList<E>::contains(E e)
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
bool LinkedList<E>::containsAll(list<E> &c)
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
bool LinkedList<E>::remove(E e)
{
    _c.remove(e);
    return true;
}

template <typename E>
bool LinkedList<E>::removeAll(list<E> &c)
{
    for (auto o : c)
    {
        remove(o);
    }
    return true;
}

template <typename E>
bool LinkedList<E>::retainAll(list<E> &c)
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
bool LinkedList<E>::isEmpty()
{
    return _c.empty();
}

template <typename E>
int LinkedList<E>::size()
{
    return _c.size();
}

template <typename E>
void LinkedList<E>::clear()
{
    _c.clear();
}

template <typename E>
typename list<E>::iterator LinkedList<E>::iterator()
{
    return _c.begin();
}

template <typename E>
bool LinkedList<E>::offer(E e)
{
    _c.push_back(e);
    return true;
}

template <typename E>
E LinkedList<E>::poll()
{
    E tmp;
    tmp = _c.front();
    _c.pop_front();
    return tmp;
}

template <typename E>
E LinkedList<E>::element()
{
    return _c.front();
}

template <typename E>
bool LinkedList<E>::removeAll(vector<E> &c)
{

    for (auto o : c)
    {
        remove(o);
    }
    return true;
}

template <typename E>
bool LinkedList<E>::retainAll(vector<E> &c)
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
bool LinkedList<E>::containsAll(vector<E> &c)
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
bool LinkedList<E>::addAll(vector<E> &c)
{
    for (auto o : c)
    {
        add(o);
    }

    return true;
}
} // namespace GTU
