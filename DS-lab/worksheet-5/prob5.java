
import java.lang.reflect.Array;
import java.util.Arrays;


class Solution{
   public int[][] normalize(int matrix[][], int row, int col){
       int m = matrix.length,n = matrix[0].length,rcol=0,rrow=0,i,j,count=0;
       boolean valid = m*n==row*col;
       int[][] returnMatrix = new int[row][col];


       if(valid){
           for(i = 0;i<row;i++){
               for(j=0;j<col;j++){
                   if(rcol==n){
                       rrow++;
                       rcol=0;
                   }
                   returnMatrix[i][j]=matrix[rrow][rcol];
                   rcol++;
               }
           }
       }
       return returnMatrix;
   }
}


public class Main {
   public static void main(String[] args) {
       int[][] mat = {{1,2},{3,4}};
       Solution s = new Solution();
       int[][] result = s.normalize(mat,1,4);


       System.out.println(Arrays.deepToString(result));
   }
}