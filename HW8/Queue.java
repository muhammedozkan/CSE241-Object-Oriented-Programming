/**
 * Queue.java
 * 
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since 2019
 */
// Queues order elements in a FIFO (first-in-first-out) manner. There is no
// random access with
// this Collection. Some functions throw exceptions.
public interface Queue<E> extends Collection<E> {
	/**
	 * Inserts the specified element into this queue if it is possible to do so
	 * immediately without violating capacity restrictions, returning
	 * <tt>true</tt> upon success and throwing an <tt>IllegalStateException</tt>
	 * if no space is currently available.
	 * 
	 * @param e
	 *            the element to add
	 * @return <tt>true</tt> (as specified by {@link Collection#add})
	 */
	public boolean add(E e);

	/**
	 * Inserts the specified element into this queue if it is possible to do so
	 * immediately without violating capacity restrictions. When using a
	 * capacity-restricted queue, this method is generally preferable to
	 * {@link #add}, which can fail to insert an element only by throwing an
	 * exception.
	 * 
	 * @param e
	 *            the element to add
	 * @return <tt>true</tt> if the element was added to this queue, else
	 *         <tt>false</tt>
	 */
	public boolean offer(E e);

	/**
	 * Retrieves and removes the head of this queue, or returns <tt>null</tt> if
	 * this queue is empty.
	 * 
	 * @return the head of this queue, or <tt>null</tt> if this queue is empty
	 */
	public E poll();

	/**
	 * Retrieves, but does not remove, the head of this queue. This method
	 * differs from  only in that it throws an exception if
	 * this queue is empty.
	 * 
	 * @return the head of this queue
	 */
	public E element();

}