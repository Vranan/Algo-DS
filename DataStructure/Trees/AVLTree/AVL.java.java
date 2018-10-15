import java.io.*;
import java.util.Scanner;

class AVLTree {
    AVLNode root;
    AVLTree() {
        root = null;
    }

    public void insert (Book bookObj) {
        root = insertNode(root, bookObj);
    }

    public AVLNode insertNode (AVLNode root, Book bookObj) {
        
        // Normal BST Insertion
        if (root == null) {
            return (new AVLNode(bookObj));
        }

        String key = bookObj.ISBN;

        if (Integer.parseInt(key) < Integer.parseInt(root.key)) {
            root.leftPtr = insertNode(root.leftPtr, bookObj);
        }
        else if (Integer.parseInt(key) > Integer.parseInt(root.key)) {
            root.rightPtr = insertNode(root.rightPtr, bookObj);
        }
        else {
            return root;
        }

        // Update heights
        root.height = 1 + max(height(root.leftPtr), height(root.rightPtr));

        // Compute Balance
        int balance = currentBalance(root);

        // Fix Left-Left Case
        if (balance > 1 && Integer.parseInt(key) < Integer.parseInt(root.leftPtr.key)) {
            System.out.println("Imbalance occured at inserting ISBN " + key + "; Fixed in Right Rotation");
            return rotateRight(root);
        }

        // Fix Right-Right Case
        if (balance < -1 && Integer.parseInt(key) > Integer.parseInt(root.rightPtr.key)) {
            System.out.println("Imbalance occured at inserting ISBN " + key + "; Fixed in Left Rotation");
            return rotateLeft(root);
        }

        // Fix Left-Right Case
        if (balance > 1 && Integer.parseInt(key) > Integer.parseInt(root.leftPtr.key)) {
            System.out.println("Imbalance occured at inserting ISBN " + key + "; Fixed in Left-Right Rotation");
            root.leftPtr = rotateLeft(root.leftPtr);
            return rotateRight(root);
        }

        // Fix Right-Left Case
        if (balance < -1 && Integer.parseInt(key) < Integer.parseInt(root.rightPtr.key)) {
            System.out.println("Imbalance occured at inserting ISBN " + key + "; Fixed in Right-Left Rotation");
            root.rightPtr = rotateRight(root.rightPtr);
            return rotateLeft(root);
        }

        return root;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(AVLNode node) {
        if (node == null) {
            return -1;
        }
        else {
            return node.height;
        }
    }

    int currentBalance(AVLNode node) {
        if (node == null) {
            return 0;
        }
        else {
            return height(node.leftPtr) - height(node.rightPtr);
        }
    }

    AVLNode rotateRight (AVLNode node) {
        AVLNode Lchild = node.leftPtr;
        AVLNode RLchild = Lchild.rightPtr;
        
        // Perform rotation
        Lchild.rightPtr = node;
        node.leftPtr = RLchild;

        // Update heights
        node.height = 1 + max(height(node.leftPtr), height(node.rightPtr));
        Lchild.height = 1 + max(height(Lchild.leftPtr), height(Lchild.rightPtr));

        // Return new root
        return Lchild;
    }

    AVLNode rotateLeft (AVLNode node) {
        AVLNode Rchild = node.rightPtr;
        AVLNode LRchild = Rchild.leftPtr;
        
        // Perform rotation
        Rchild.leftPtr = node;
        node.rightPtr = LRchild;

        // Update heights
        node.height = 1 + max(height(node.leftPtr), height(node.rightPtr));
        Rchild.height = 1 + max(height(Rchild.leftPtr), height(Rchild.rightPtr));

        // Return new root
        return Rchild;
    }
}

class AVLNode {
    String key;
    Book value; //create a class representing a bookObj with minimum attributes
    int height;
    AVLNode leftPtr;
    AVLNode rightPtr;
    public AVLNode(Book bookObj) { 
        key = bookObj.ISBN; 
        value = bookObj;
        leftPtr = rightPtr = null; 
    }
}

class Book {
    String ISBN;
    String title;
    String author;
    public Book(String isbn, String bookTitle, String name) {
        this.ISBN = isbn;
        this.title = bookTitle;
        this.author = name;
    }
}

class driver {
    public static void main(String[] args) throws IOException {
        File bookFile = new File(".\\books.txt");
        FileReader fr = new FileReader(bookFile);
        LineNumberReader ln = new LineNumberReader(fr);
        int i = 0;

        int line = 0;
    		    
    	while (ln.readLine() != null) {
    	    line++;
    	}

        ln.close();
        
        Scanner scanner = new Scanner(bookFile);
        String[] bookObj = new String[line];

        while (scanner.hasNextLine()) {
            bookObj[i] = scanner.nextLine();
            i++;
        }

        // Create AVLTree Object
        
        AVLTree tree = new AVLTree();

        for (i = 0; i < bookObj.length; i++) {
            String[] splited = bookObj[i].split("\\s+");
            Book bk = new Book(splited[0], splited[1], splited[2]);
            System.out.println("Inserting a new Book with ISBN = " + splited[0] + " -- ");
            tree.insert(bk);
        }

    }
}