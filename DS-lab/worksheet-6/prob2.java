import java.util.*;

class validParenthesis{
    Stack<Character> s1;
    int count;
    public validParenthesis(){
        s1 = new Stack<>();
        count = 0;
    }    
    
    public int enter(String s){
        for(char c : s.toCharArray()){
            if(c=='('){
                s1.push(c);
            }else{
                if(!s1.empty()){
                    count+=2;
                    s1.pop();
                }
            }
        }
        return count;
    }
}


public class Main {
    public static void main(String[] args) {
        validParenthesis vp = new validParenthesis();
        int res = vp.enter("(()");
        System.out.println(res);
    }
}