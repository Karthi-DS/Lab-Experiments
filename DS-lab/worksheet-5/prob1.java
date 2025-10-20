class Solution {
    public void rotate(int[][] matrix) {
        int i, j;
        int length = matrix[0].length;
        for(i=0;i<length;i++){
            for(j=0;j<length;j++){
                if(i<j){
                    int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
                }
            }
        }
        for(i=0;i<length;i++){
            for(j=0;j<length/2;j++){
                int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][length-1-j];
            matrix[i][length-1-j] = tmp;
            }
            
        }
    }
}