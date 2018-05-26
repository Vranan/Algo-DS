//import java.util.Scanner;
import java.util.ListIterator;
public class StackOfStrings {
    private String[] S;
    private int front = 0;
    private int back = 0;
   
    public StackOfStrings(int size) {
        S = new String[size];
        back = size;
    }
	
    private void push(String str) {
        if (front < back) {
            S[front] = str;
            System.out.println("1.1 push: str = " + str + ", S[" + front + "] = " + S[front]);
            front++;
        } 
        else {
            System.out.println("1.2 push: Stack is full -- ");
        }
    }
   
    private String pop() {
        if (front < 0) {
            //System.out.println("Stack is Empty -- ");
            return ("2.2 pop: Stack is Empty");
        }
        String str = S[--front];
        S[front] = null;
		System.out.println("2.1 pop: str = " + str + ", front = " + front + ", S[" + front + "] = " + S[front]);
		return str;
    }
   
    private boolean isEmpty() {
		return (front == 0);
    }
   
    private boolean isFull() {
		return (front == back);
    }
   
    private void iter() {
		for (int i = 0; i < front; i++) {
		    System.out.println("5.1 iter: itr = " + S[i]);
		}
	}
	
	private class ListIterator implements Iterator<Item> {
	    private Node current = front;
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
	
   
    public static void main(String[] args) {
		// Taking the size of the stack to be 50.
        StackOfStrings st = new StackOfStrings(50);
        /* Scanner in = new Scanner(System.in);
        int i = 0;
        // Running for 5 user inputs
        while (i < 5) {
            String s = in.nextLine();
            System.out.println("1. s = " + s);
            if (s.equals("candy")) {
                System.out.println("2. " + st.pop());
            }
            else {
               System.out.println("3. Pushing String s = " + s);
               st.push(s);
            }
            i++;
        }
        in.close(); */
		
	    st.push("Apple");
	    st.push("Microsoft");
		st.push("Facebook");
		st.push("Google");
		st.push("Amazon");
		st.push("Wallmart");
		ListIterator ltr = st.iterator();
		while (ltr.hasNext()) {
		    System.out.println(ltr.next());
		}
	    /*st.iter();
	    st.pop();
	    st.iter();
	    st.pop();
	    st.iter();
	    st.pop();
	    st.iter();
		st.pop();
	    st.iter();
	    st.pop();
	    st.iter();
	    st.pop();
	    st.iter();
		st.pop();
	    st.iter();
       
        if (st.isEmpty()) {
            System.out.println("4. The Stack is Empty");
        }
        else if (st.isFull()) {
            System.out.println("5. The Stack is Full");
        }
           */		
    }
  
}