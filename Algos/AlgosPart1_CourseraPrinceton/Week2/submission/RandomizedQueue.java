import edu.princeton.cs.algs4.StdRandom;
// import edu.princeton.cs.algs4.StdStats;
import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item> {
	private Item[] arr;
	private int front;
	private  int sz;
 
	public RandomizedQueue() {                 // construct an empty randomized queue
		front = 0;
		sz = 0;
		resizingArrayOfItems();
	}
 
	public boolean isEmpty() {                 // is the randomized queue empty? 
		return (front == 0);
	}
	
	public int size() {                        // return the number of items on the randomized queue
		return sz;
	}
 
	public void resizingArrayOfItems() {
		arr = (Item[]) new Object[1];
	}
 
	public void resize(int capacity) {
		Item[] copy = (Item[]) new Object[capacity];
		for (int i = 0; i < front; i++) {
			if (arr[i] == null) {
				continue;
			}
		copy[i] = arr[i];
	}
	arr = copy;
	}
 
	public void enqueue(Item item) {           // add the item
	    // System.out.println("enqueue: item = " + item);
		if (item == null) {
			throw new java.lang.IllegalArgumentException();
		}
  
		if (front == arr.length) {
			resize (2* arr.length);
		}
  
		arr[front++] = item;
		sz++;
	}
 
	public Item dequeue() {                    // remove and return a random item
	    if (isEmpty()) {
			throw new java.util.NoSuchElementException();
		}
		int rand = StdRandom.uniform(0, front+1);
		Item ar = arr[rand];
		// System.out.println("dequeue: rand = " + rand + ", ar = " + ar);
		arr[rand] = arr[--front];
		arr[front] = null;
		if (front == arr.length/4) {
			resize (arr.length/2);
		}
		sz--;
		return ar;
	}
 
	public Item sample() {                     // return a random item (but do not remove it)
	    if (isEmpty()) {
			throw new java.util.NoSuchElementException();
		}
		int rand = StdRandom.uniform(0, front);
		return (arr[rand]);
	}
	
	public Iterator<Item> iterator() {        // return an independent iterator over items in random order
		return new ListIterator();
	}
 
	private class ListIterator implements Iterator<Item> {
		private int current = StdRandom.uniform(0, front);
     
		public boolean hasNext() {
			// System.out.println("current = " + current + ", back = " + back);
			return (current < front);
		}
  
		public void remove() {
			throw new java.lang.UnsupportedOperationException();
		}
  
		public Item next() {
			if (!hasNext()) {
				throw new java.util.NoSuchElementException(); 
			}
			Item item = arr[current];
			current = StdRandom.uniform(0, front);
			return item;
		} 
	}
 
	/* public static void main(String[] args)  { // unit testing (optional)
		RandomizedQueue<String> rd = new RandomizedQueue<String>();
		rd.enqueue("He");
		rd.enqueue("is");
		rd.enqueue("AB");
		rd.enqueue("DE");
		rd.enqueue("VI");
		System.out.println("size = " + rd.size());
		System.out.println("100. main: dequeue = " + rd.dequeue());
		System.out.println("100. main: dequeue = " + rd.dequeue());
		System.out.println("size = " + rd.size());
		rd.enqueue("LI");
		rd.enqueue("ERS");
		System.out.println("size = " + rd.size());
		System.out.println("100. main: dequeue = " + rd.dequeue());
		System.out.println("100. main: sample = " + rd.sample());
		System.out.println("size = " + rd.size());
	} */
}