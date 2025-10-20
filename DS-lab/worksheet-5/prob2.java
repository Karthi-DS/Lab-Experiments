import java.util.*;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = 0,n = 0;
        List<Integer> result = new ArrayList<>();;
        int top=0,left=0,right=matrix[0].length-1,bottom=matrix.length-1;
        for(int i =0;i<matrix.length*matrix[0].length;i++){
            if(m==top && n<right){
                result.add(matrix[m][n]);
                n++; 
            }else if(n==right && m!=bottom){
                result.add(matrix[m][n]);
                m++;
            }else if(m==bottom && n!= left){
                result.add(matrix[m][n]);
                n--;
            }else{
                top++;
                right--;
                bottom--;
                m = top;
                n = left;
            }
        }
        return result;
    }
}