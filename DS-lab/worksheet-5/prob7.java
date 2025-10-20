import java.util.*;


class Solution{


   HashMap<String,ArrayList<String>> group;
   public Solution(){
       group = new HashMap<>();
   }
   public String getHash(String s){
       int[] count = new int[26];
       int i;
       for(i =0;i<s.length();i++) {
           char c = s.charAt(i);
           count[c - 'a']++;
       }
       StringBuilder hash = new StringBuilder();
       for(i=0;i<26;i++){
           if(count[i]>0){
               hash.append((char)(i+'a')).append(count[i]);
           }
       }
       return hash.toString();
   }
   public List<List<String>> groupAnagrams(String[] args){
       for(String s:args){
           String hash = getHash(s);
           if(group.containsKey(hash)){
               ArrayList<String> prev = new ArrayList<>(group.get(hash));
               prev.add(s);
               group.put(hash,prev);
         //alternative: group.get(hash).add(s);
           }else{
               ArrayList<String> newList = new ArrayList<>();
               newList.add(s);
               group.put(hash,newList);
           }
       }
       return new ArrayList<>(group.values());
   }
}


public class Main {
   public static void main(String[] args){
       String[] argument = {"eat","tea","tan","ate","nat","bat"};
       Solution s = new Solution();
       List<List<String>> res = s.groupAnagrams(argument);
       System.out.println(res);
   }
}

