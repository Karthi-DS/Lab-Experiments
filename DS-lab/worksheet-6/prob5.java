import java.util.*;

class StackPopCount {  
    public static List<Integer> countPopOperations(Stack<Integer> originalStack, int[] arr) {
        Stack<Integer> stack = new Stack<>();
        stack.addAll(originalStack); // copy of original stack

        List<Integer> result = new ArrayList<>();

        for (int x : arr) {
            int pops = 0;

            
            if (!stack.contains(x)) {
                result.add(0);
                continue;
            }

 
            while (!stack.isEmpty()) {
                int top = stack.pop();
                pops++;
                if (top == x) break;
            }

            result.add(pops);
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4); 
        int[] arr = {3, 2, 4};

        List<Integer> result = StackPopCount.countPopOperations(stack, arr);
        System.out.println("Pop counts: " + result);
    }
}