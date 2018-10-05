public class StackOfStringsLinkedList {
	// Linked List based implementation of Stacks
	private class node {
		String str;
		node next;
	}
	
	private node start;
	private node itr;
	// private node itr1;
	
	StackOfStringsLinkedList() {
		//System.out.println("0.1  start = " + start + ", itr = " + itr + ", itr1 = " + itr1);
	}
	
	private void push(String str) {
	    
		System.out.println("1. push: str = " + str);
		//System.out.println("1.1. push: start = " + start + ", itr = " + itr);
		node new_node = new node();
		new_node.str = str;
		if (itr == null) {
			itr = new_node;
			start = itr;
		}
		else {
			new_node.next = itr;
			itr = new_node;
		}
		
	}
	
	private String pop() {
	    if (itr == start) {
			return "-- Stack is Empty --";
		}
		else {
			String st = itr.str;
			//System.out.println("2.1 pop = " + st);
			itr = itr.next;
			return st;
		}
	}
	
	private boolean isEmpty() {
		return (itr == start);
	}
	
	private void iter() {
	    node new_node = new node();
		new_node = itr;
		//System.out.println("3. iter: start = " + start + ", itr = " + itr);
		//System.out.println("4.1. start.next = " + start.next);
		while (new_node != null) {
			System.out.println("4.2 iter: itr = " + new_node.str);
			new_node = new_node.next;
		}
	}
	
	public static void main (String[] args) {
	    StackOfStringsLinkedList st = new StackOfStringsLinkedList();
		st.push("Apple");
		st.push("Microsoft");
		st.push("Facebook");
		st.push("Google");
		st.push("Amazon");
		st.push("Wallmart");
        st.iter();
		System.out.println("5.1 pop: " + st.pop());
		st.iter();
		System.out.println("5.2 pop: " + st.pop());
		st.iter();
		System.out.println("5.3 pop: " + st.pop());
		st.iter();
		System.out.println("5.4 pop: " + st.pop());
		st.iter();
		System.out.println("5.5 pop: " + st.pop());
		st.iter();
		System.out.println("5.6 pop: " + st.pop());
		st.iter();
		System.out.println("5.7 pop: " + st.pop());
		st.iter();
		System.out.println("5.8 pop: " + st.pop());
		st.iter();
		
	}
	
	
}