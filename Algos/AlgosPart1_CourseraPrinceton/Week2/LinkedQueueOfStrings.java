
public class LinkedQueueOfStrings<Item> {
    
	private class Node {
	    Item s;
		Node next;
	}
	
	private Node first, last;
	
	public boolean isEmpty() {
	    return (first == null);
	}
	
	public void enqueue(Item s) {
	    Node new_node = new Node();
		new_node.s = s;
		new_node.next = null;
		if (isEmpty()) {
			last = new_node;
			first = last;
		} 
		else {
			last.next = new_node;
			last = new_node;
		}
	}
	
	public Item dequeue() {
	    Item item = first.s;
		first = first.next;
		if (isEmpty()) {
			last = null;
		}
		return item;
	}
	
	public void itr() {
	    Node root = new Node();
		root = first;
		if (first == null) {
		    System.out.println("Queue is Empty");
			return;
		}
		while (root != null) {
			System.out.println(root.s);
			root = root.next;
		}
	}
	
	public static void main(String[] args) {
	    LinkedQueueOfStrings<String> ls = new LinkedQueueOfStrings<String>();
		if (ls.isEmpty()) {
		    System.out.println("Stack is Empty");
		}
		
		ls.enqueue("Hello");
		ls.enqueue("World");
		ls.enqueue("This is awesome");
		ls.enqueue("The world is amazing");
		ls.enqueue("Full of dangers and possibilities");
		System.out.println("1. itr");
        ls.itr();
		System.out.println("dequeue");
		ls.dequeue();
		System.out.println("2. itr");
		ls.itr();
		ls.dequeue();
		System.out.println("3. itr");
		ls.itr();
		ls.dequeue();
		System.out.println("4. itr");
		ls.itr();
		ls.dequeue();
		System.out.println("5. itr");
		ls.itr();
		ls.dequeue();
		System.out.println("6. itr");
		ls.itr();
			
	}
	
}