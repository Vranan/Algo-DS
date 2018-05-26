import java.util.Iterator;
public class Deque<Item> implements Iterable<Item> {
    // private Item[] arr;
	
	private int sz;
   
    private class Node {
		Item item;
		Node next;
		Node previous;
    }
 
    private Node start;
	private Node end;

		// private int start;
		// private int end;   

		public Deque() {  // construct an empty deque
		sz = 0;
	}
 
    public boolean isEmpty() {                 // is the deque empty?
		return (start == null);
	}
 
    public int size() {                       // return the number of items on the deque
		return sz;
	}
 
    public void addFirst(Item item) {          // add the item to the front
		if (item == null) {
			throw new java.lang.IllegalArgumentException("item is null");
		}
		Node newNode = new Node();
		newNode.item = item;
		if (start == null) {
			start = newNode;
			end = newNode;
			// System.out.println("addFirst.1: start = " + start + ", end = " + end + ", item = " + item);
		}
		else {
			newNode.next = start;
			newNode.previous = null;
			start.previous = newNode;
			start = newNode;
			// System.out.println("addFirst.2: start = " + start + ", end = " + end + ", item = " + item);
		}
		sz++; 
    }
 
    public void addLast(Item item)  {         // add the item to the end
		if (item == null) {
			throw new java.lang.IllegalArgumentException("item is null ");
		}
		Node newNode = new Node();
		newNode.item = item;
		newNode.next = null;

		if (start == null) {
			end = newNode;
			start = end;
			// System.out.println("addLast.1: end   = " + end + ", start = " + start);
		} 
		else {
			end.next = newNode;
			newNode.previous = end;
			end = newNode;
			// System.out.println("addLast.2: end   = " + end + ", start = " + start + ", newNode = " + newNode + ", newNode.previous = " + newNode.previous + ", end.previous = " + end.previous);
		}
		sz++;
	}
 
    public Item removeFirst() {               // remove and return the item from the front
		if (isEmpty()) { 
			throw new java.util.NoSuchElementException();
	}
  
		Item it = start.item;
		// System.out.println("remFist.1: start = " + start + ", end = " + end + ", start.next = " + start.next + ", it = " + it);
		start = start.next;
		// System.out.println("remFist.2: start = " + start + ", end = " + end + ", start.next = " + start.next + ", it = " + it);
		if (start != null) start.previous = null;
		else end = null;
		sz--;
		return it;
	}
 
    public Item removeLast() {                 // remove and return the item from the end
		if (isEmpty()) { 
			throw new java.util.NoSuchElementException();
		}
		Item it = end.item;
		// System.out.println("remLast.1: end   = " + end + ", it = " + it + ", end.previous = " + end.previous);
		end = end.previous;
		// System.out.println("remLast.2: end   = " + end + ", it = " + it + ", start = " + start);
		if (end != null) end.next = null;     // If there was only one element in the dequeue and it was removed.
		else start = null;
		sz--;
		return it;
	}
 
    public Iterator<Item> iterator() {         // return an iterator over items in order from front to end
		return new ListIterator();
    }
 
	private class ListIterator implements Iterator<Item> {
		private Node itr = start;

		public boolean hasNext() {
			return (itr != null);
		}

		public void remove() {
			throw new java.lang.UnsupportedOperationException();
		}

		public Item next() {
			if (!(hasNext())) {
				throw new java.util.NoSuchElementException();
			}
			Item it = itr.item;
			return it;
		}
 }
 
    /* public static void main(String[] args)  { // unit testing (optional)
         Deque<Integer> deque = new Deque<Integer>();
         // Iterator<String> it = dq.iterator();
		 // deque.size();
         // deque.isEmpty();         
         // deque.addLast(2);
         // deque.removeLast();

		 deque.addLast(0);
         deque.addLast(1);
         deque.addLast(2);
         System.out.println(deque.removeFirst());  
         System.out.println(deque.removeFirst());     
         System.out.println(deque.removeLast());     
         deque.addLast(6);
         System.out.println("Is Empty = " + deque.isEmpty());        
         System.out.println(deque.size());           
         System.out.println(deque.removeLast());      
         System.out.println("Is Empty = " + deque.isEmpty());
    } */
}