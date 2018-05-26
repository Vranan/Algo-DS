public ResizingArrayOfStrings() {
    s = new String[1];
}
	
public void push() {
    if (N == s.length) {
		resize (2* s.length);
	}
	s[N++] = item;
}

public void resize(int capacity) {
	String[] copy = new String[capacity];
	for (int i = 0; i < N; i++) {
		copy[i] = s[i];
	}
    s = copy;
}	

	