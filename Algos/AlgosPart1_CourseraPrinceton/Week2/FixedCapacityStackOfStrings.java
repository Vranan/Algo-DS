import java.util.Iterator;
public class FixedCapacityStackOfItemsImplementation<Item> implements Iterable<Item>{
	private Item[] s;
	private int N = 0;
	
	private class ListIterator implements Iterator<Item> {
	    private Node current = first;
		public boolean hasNext() {
		    return current != null;
		}
		//public void remove() {
		//}
		public Item next() {
		    Item item = current.item;
			current = current.next;
			return item;
		}
	}
	
	public Iterator<Item> iterator() {
	    return new ListIterator();
	}
	
	/*public Iterator<Item> iterator() { 
		return new ReverseArrayIterator(); 
	}
	private class ReverseArrayIterator implements Iterator<Item> {
		private int i = N;
		public boolean hasNext() { return i > 0; }
		//public void remove() {  //not supported  }
		public Item next() { return s[--i]; }
	} */
	
	public FixedCapacityStackOfItems(int capacity) { 
	    // s = new Item[capacity];  This is not going to work.
		s = (Item[]) new Object(capacity);
	}
	
	public boolean isEmpty() { 
	    return (N == 0);
	}
	
	public ResizingArrayOfItems() {
		s = (Item[]) new Object[1];
	}
	
	public void resize(int capacity) {
		Item[] copy = (Item[]) new Object[capacity];
		for (int i = 0; i < N; i++) {
			copy[i] = s[i];
		}
		s = copy;
	}	
	
    public void push(Item item) {
		if (N == s.length) {
			resize (2* s.length);
		}
		s[N++] = item;
	}
	
	public Item pop() {
		Item item = s[--N];
		s[N] = null;
		if (N > 0 && N == s.length/4) {
			resize(s.length/2);
		}
		return item;
	}
	
	public static void main (String[] args) {
	    FixedCapacityStackOfItemsImplementation<String> st = new FixedCapacityStackOfItemsImplementation<String>();
		st.push("Apple");
		st.push("Microsoft");
		st.push("Facebook");
		st.push("Google");
		st.push("Amazon");
		st.push("Wallmart");
		System.out.println("5.1 pop: " + st.pop());
		System.out.println("5.2 pop: " + st.pop());
		System.out.println("5.3 pop: " + st.pop());
		System.out.println("5.4 pop: " + st.pop());
		System.out.println("5.5 pop: " + st.pop());
		System.out.println("5.6 pop: " + st.pop());
		System.out.println("5.7 pop: " + st.pop());
		System.out.println("5.8 pop: " + st.pop());
		
	}
}