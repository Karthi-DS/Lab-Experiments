import java.util.*;

class postFixEval {
    Stack<Integer> s;
    
    public postFixEval() {
        s = new Stack<>();
    }
    
    public int eval(String str){
        for(char c:str.toCharArray()){
            if(Character.isDigit(c)){
                s.add(Character.getNumericValue(c));
            }else{
                int opr2 = s.pop();
                int opr1 = s.pop();
                int res;
                if(c=='+'){
                    res = opr1+opr2;
                }else if(c=='-'){
                    res = opr1-opr2;
                }else if(c=='*'){
                    res = opr1*opr2;
                }else{
                    res = opr1/opr2;
                }
                s.add(res);
            }
        }
        return s.pop();
    }
}

public class Main {
    public static void main(String[] args) {
       postFixEval pe = new postFixEval();
       int res = pe.eval("245+*");
       System.out.println("result : "+res);
    }
}