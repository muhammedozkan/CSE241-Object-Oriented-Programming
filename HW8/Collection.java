/**
 * Collection.java
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */
import java.util.Iterator;

//This is a generic class with one generic parameters which is the generic type E
public interface Collection<E> extends Iterable<E> {
	/**
	 * Returns the number of elements in this collection. If this collection
	 * contains more than <tt>Integer.MAX_VALUE</tt> elements, returns
	 * <tt>Integer.MAX_VALUE</tt>.
	 * 
	 * @return the number of elements in this collection
	 */
	public int size();

	/**
	 * Returns <tt>true</tt> if this collection contains no elements.
	 * 
	 * @return <tt>true</tt> if this collection contains no elements
	 */
	public boolean isEmpty();

	/**
	 * Returns <tt>true</tt> if this collection contains the specified element.
	 * More formally, returns <tt>true</tt> if and only if this collection
	 * contains at least one element <tt>e</tt> such that
	 * <tt>(o==null&nbsp;?&nbsp;e==null&nbsp;:&nbsp;o.equals(e))</tt>.
	 * 
	 * @param o
	 *            element whose presence in this collection is to be tested
	 * @return <tt>true</tt> if this collection contains the specified element
	 */
	public boolean contains(Object o);

	/**
	 * Returns an iterator over the elements in this collection. There are no
	 * guarantees concerning the order in which the elements are returned
	 * (unless this collection is an instance of some class that provides a
	 * guarantee).
	 * 
	 * @return an <tt>Iterator</tt> over the elements in this collection
	 */
	public Iterator<E> iterator();

	/**
	 * Ensures that this collection contains the specified element (optional
	 * operation). Returns <tt>true</tt> if this collection changed as a result
	 * of the call. (Returns <tt>false</tt> if this collection does not permit
	 * duplicates and already contains the specified element.)
	 * <p>
	 * 
	 * Collections that support this operation may place limitations on what
	 * elements may be added to this collection. In particular, some collections
	 * will refuse to add <tt>null</tt> elements, and others will impose
	 * restrictions on the type of elements that may be added. Collection
	 * classes should clearly specify in their documentation any restrictions on
	 * what elements may be added.
	 * <p>
	 * 
	 * If a collection refuses to add a particular element for any reason other
	 * than that it already contains the element, it <i>must</i> throw an
	 * exception (rather than returning <tt>false</tt>). This preserves the
	 * invariant that a collection always contains the specified element after
	 * this call returns.
	 * 
	 * @param e
	 *            element whose presence in this collection is to be ensured
	 * @return <tt>true</tt> if this collection changed as a result of the call
	 */
	public boolean add(E e);

	/**
	 * Removes a single instance of the specified element from this collection,
	 * if it is present (optional operation). More formally, removes an element
	 * <tt>e</tt> such that
	 * <tt>(o==null&nbsp;?&nbsp;e==null&nbsp;:&nbsp;o.equals(e))</tt>, if this
	 * collection contains one or more such elements. Returns <tt>true</tt> if
	 * this collection contained the specified element (or equivalently, if this
	 * collection changed as a result of the call).
	 * 
	 * @param o
	 *            element to be removed from this collection, if present
	 * @return <tt>true</tt> if an element was removed as a result of this call
	 */
	public boolean remove(Object o);

	/**
	 * Returns <tt>true</tt> if this collection contains all of the elements in
	 * the specified collection.
	 * 
	 * @param c
	 *            collection to be checked for containment in this collection
	 * @return <tt>true</tt> if this collection contains all of the elements in
	 *         the specified collection
	 */
	public boolean containsAll(Collection<?> c);

	/**
	 * Adds all of the elements in the specified collection to this collection
	 * (optional operation). The behavior of this operation is undefined if the
	 * specified collection is modified while the operation is in progress.
	 * (This implies that the behavior of this call is undefined if the
	 * specified collection is this collection, and this collection is
	 * nonempty.)
	 * 
	 * @param c
	 *            collection containing elements to be added to this collection
	 * @return <tt>true</tt> if this collection changed as a result of the call
	 */
	public boolean addAll(Collection<?> c);

	/**
	 * Removes all of this collection's elements that are also contained in the
	 * specified collection (optional operation). After this call returns, this
	 * collection will contain no elements in common with the specified
	 * collection.
	 * 
	 * @param c
	 *            collection containing elements to be removed from this
	 *            collection
	 * @return <tt>true</tt> if this collection changed as a result of the call
	 */
	public boolean removeAll(Collection<?> c);

	/**
	 * Retains only the elements in this collection that are contained in the
	 * specified collection (optional operation). In other words, removes from
	 * this collection all of its elements that are not contained in the
	 * specified collection.
	 * 
	 * @param c
	 *            collection containing elements to be retained in this
	 *            collection
	 * @return <tt>true</tt> if this collection changed as a result of the call
	 */
	public boolean retainAll(Collection<?> c);

	/**
	 * Removes all of the elements from this collection (optional operation).
	 * The collection will be empty after this method returns.
	 * 
	 */
	public void clear();

	public Object get(int index);

}