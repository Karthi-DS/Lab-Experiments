class Solution {
    public int count(int[] row, int l, int r) {
        for (int i = l; i < r; i++) {
            if (row[i] < 0) {
                return i; // return index of first negative
            }
        }
        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        int totalCount = 0;
        int[][] matrix = {
            {4, 3, 2, -1},
            {2, 3, -1, -1},
            {4, 2, -1, -2}
        };

        int cols = matrix[0].length;
        int r = cols;
        Solution s = new Solution();

        for (int i = 0; i < matrix.length; i++) {
            int tmpCount = s.count(matrix[i], 0, r);

            if (tmpCount >= 0) { 
                r = tmpCount;  
                totalCount += (matrix.length-i);
            }
        }

        System.out.println(totalCount); // ✅ 3
    }
}