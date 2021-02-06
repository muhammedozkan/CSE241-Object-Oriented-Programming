/**
 * ArrayList.java
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

//Implements List functions
public class ArrayList<E> implements List<E> {
	private Object[] _arr;
	private int _size;
	private int _capacity;

	// Constructor
	public ArrayList() {
		_capacity = 5;
		_arr = new Object[_capacity];
		_size = 0;
	}

	// return iterator
	public Iterator<E> iterator() {
		return new Itr();
	}

	// return element of index number
	public Object get(int index) {
		if (index >= _size)
			throw new IndexOutOfBoundsException();
		return _arr[index];
	}

	// return size
	public int size() {
		return _size;
	}

	public boolean isEmpty() {
		return _size == 0;
	}

	public boolean contains(Object o) {
		for (Object tmp : _arr) {
			if (tmp == o) {
				return true;
			}
		}
		return false;
	}

	public boolean add(E e) {

		if (_capacity > _size) {
			_arr[_size] = e;
			_size++;
		} else {
			Object tmp[] = new Object[_capacity];

			for (int i = 0; i < _capacity; i++) {
				tmp[i] = _arr[i];
			}

			_arr = new Object[_capacity + 5];

			for (int i = 0; i < _capacity; i++) {
				_arr[i] = tmp[i];
			}
			_capacity += 5;

			_arr[_size] = e;
			_size++;
		}

		return true;
	}

	public boolean retainAll(Collection<?> c) {
		int flag;
		for (Object o : _arr) {
			flag = 0;
			for (int i = 0; i < c.size(); i++) {
				if (o == c.get(i)) {
					flag = 1;
				}
				if (flag == 0) {
					remove(o);
				}
			}
		}
		return true;
	}

	public boolean containsAll(Collection<?> c) {
		int flag;
		for (Object o : _arr) {
			flag = 0;
			for (int i = 0; i < c.size(); i++) {
				if (o == c.get(i)) {
					flag = 1;
				}
				if (flag == 0) {
					return false;
				}
			}
		}
		return true;
	}

	public boolean addAll(Collection<?> c) {

		for (int j = 0; j < c.size(); j++) {
			if (_capacity > _size) {
				_arr[_size] = c.get(j);
				_size++;
			} else {
				Object tmp[] = new Object[_capacity];

				for (int i = 0; i < _capacity; i++) {
					tmp[i] = _arr[i];
				}

				_arr = new Object[_capacity + 5];

				for (int i = 0; i < _capacity; i++) {
					_arr[i] = tmp[i];
				}
				_capacity += 5;

				_arr[_size] = c.get(j);
				_size++;
			}
		}
		return true;
	}

	public boolean removeAll(Collection<?> c) {

		for (int i = 0; i < c.size(); i++) {
			remove(c.get(i));
		}
		return true;
	}

	public boolean remove(Object o) {
		int count = 0;
		for (int i = 0; i < _size; i++) {
			if (_arr[i] == o) {
				_arr[i] = null;
				++count;
			}
		}
		Object tmp[] = new Object[_size - count];
		int j = 0;
		for (int i = 0; i < _size;) {
			if (_arr[i] == null) {
				i++;
			} else {
				tmp[j] = _arr[i];
				j++;
				i++;
			}
		}

		_size = _size - count;
		_arr = new Object[_size];

		for (int i = 0; i < _size; i++) {
			_arr[i] = tmp[i];
		}

		return true;
	}

	public void clear() {
		_capacity = 5;
		_arr = new Object[_capacity];
		_size = 0;
	}

	public String toString() {
		String str = new String();

		for (Object tmp : _arr) {
			str += tmp + "\n";
		}
		return str;
	}

	private class Itr implements Iterator<E> {
		int lastRet = -1;

		// Returns true if the iteration has more elements.
		public boolean hasNext() {
			return _capacity != _size;
		}

		// Returns the next element in the iteration and advances the iterator
		@SuppressWarnings("unchecked")
		public E next() {

			int i = _capacity;
			if (i >= _size)
				throw new NoSuchElementException();
			Object[] data = _arr;
			if (i >= data.length)
				throw new ConcurrentModificationException();
			_capacity = i + 1;
			return (E) data[lastRet = i];
		}

		// Removes from the underlying collection the last element returned by
		// this iterator
		public void remove() {
			if (lastRet < 0)
				throw new IllegalStateException();

			try {
				ArrayList.this.remove(_arr[lastRet]);
				_capacity = lastRet;
				lastRet = -1;

			} catch (IndexOutOfBoundsException ex) {
				throw new ConcurrentModificationException();
			}
		}

	}

}
