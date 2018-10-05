import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
	
    public static void main(String[] args) {
		int k = Integer.parseInt(args[0]);
		RandomizedQueue<String> rd = new RandomizedQueue<String>();
		while (!StdIn.isEmpty()) {
			rd.enqueue(StdIn.readString());
			// System.out.println("st = " + st);
		}
		
		while (k-- > 0) {
			StdOut.println(rd.dequeue());
		}
    }
}