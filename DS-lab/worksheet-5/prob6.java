import java.util.*;


class Solution{
   HashMap<Character,String> map;
   public Solution(){
       map = new HashMap<>();
       map.put('2',"abc");
       map.put('3',"def");
       map.put('4',"ghi");
       map.put('5',"jkl");
       map.put('6',"mno");
       map.put('7',"pqrs");
       map.put('8',"tuv");
       map.put('9',"wxyz");
   }
   public List<String> getCombinations(String number){
       int len = number.length(),i=0;
       List<String> result = new ArrayList<>();
       result.add("");
       for(i=0;i<len;i++){
           char n = number.charAt(i);
           String letters = map.get(n);
           List<String> newResult = new ArrayList<>();


           for(String combinations: result){
               for(char c: letters.toCharArray()){
                   newResult.add(combinations+c);
               }
           }
           result = newResult;
       }
       return result;
   }
}


public class Main {
   public static void main(String[] args) {


       Scanner scanner = new Scanner(System.in);
       Solution s = new Solution();
       System.out.println("Enter the String");
       String input = scanner.next();
       List result = s.getCombinations(input);
       System.out.println(result);
   }
}