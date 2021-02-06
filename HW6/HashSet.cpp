//============================================================================
// Name        : HashSet.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "HashSet.h"

namespace GTU
{ //Implements Set functions
template <typename E>
HashSet<E>::HashSet()
{
}

template <typename E>
bool HashSet<E>::add(E e)
{
	_c.insert(e);
	return true;
}

template <typename E>
bool HashSet<E>::addAll(set<E> &c)
{
	for (auto o : c)
	{
		add(o);
	}

	return true;
}

template <typename E>
bool HashSet<E>::contains(E e)
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
bool HashSet<E>::containsAll(set<E> &c)
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
bool HashSet<E>::remove(E e)
{
	_c.erase(e);
	return true;
}

template <typename E>
bool HashSet<E>::removeAll(set<E> &c)
{
	for (auto o : c)
	{
		remove(o);
	}
	return true;
}

template <typename E>
bool HashSet<E>::retainAll(set<E> &c)
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
bool HashSet<E>::isEmpty()
{
	return _c.empty();
}

template <typename E>
int HashSet<E>::size()
{
	return _c.size();
}

template <typename E>
void HashSet<E>::clear()
{
	_c.clear();
}

template <typename E>
typename set<E>::iterator HashSet<E>::iterator()
{
	return _c.begin();
}

} // namespace GTU
