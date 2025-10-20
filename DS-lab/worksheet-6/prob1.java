import java.util.*;

class minStack {
    Stack<Integer> s1;
    Stack<Integer> s2;
    
    public minStack() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    public void push(int x) {
        s1.push(x);
        if (s2.isEmpty() || s2.peek() >= x) {
            s2.push(x);
        }
    }
    
    public int pop() {
        if (s1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        int val = s1.pop();
        if (!s2.isEmpty() && val == s2.peek()) {
            s2.pop();
        }
        System.out.println("Popped: " + val);
        return val;
    }
    
    public int getMin() {
        if (s2.isEmpty()) {
            System.out.println("Stack is empty, no minimum");
            return -1;
        }
        System.out.println("Min: " + s2.peek());
        return s2.peek();
    }
}

public class Main {
    public static void main(String[] args) {
        minStack s = new minStack();
        s.push(3);
        s.push(2);
        s.push(10);
        s.push(1);
        s.getMin();  // Min: 1
        s.pop();     // Popped: 1
        s.getMin();  // Min: 2
        s.pop();     // Popped: 10
        s.getMin();  // Min: 2
        s.pop();     // Popped: 2
        s.getMin();  // Min: 3
        s.pop();     // Popped: 3
        s.getMin();  // Stack is empty, no minimum
    }
}

