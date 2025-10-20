#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter the no of rows: ");
    scanf("%d", &m);
    printf("Enter the no of columns: ");
    scanf("%d", &n);

    int arr[m][n];
    printf("Enter the elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Printing elements in to-and-fro order: \n");
    j=0;
    i=0;
    while(i<m){
        while(j<n && i <m){
            printf("%d",arr[i][j]);
            printf(",");
            j++;
            if(j==n){
                j--;
                i++;
                printf("\n");
                break;
            }
        }
        while(j>=0 && i <m){
            printf("%d",arr[i][j]);
            printf(",");
            j--;
            if(j==-1){
                j++;
                i++;
                printf("\n");
                break;
            }
        }
    }

    printf("\nDiagonal-major order:\n");
    for (int diag = 0; diag < m + n - 1; diag++) {
        for (i = 0; i < m; i++) {
            j = diag - i;
            if (j >= 0 && j < n) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");

    printf("\nSpiral order:\n");
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (j = left; j <= right; j++)
            printf("%d ", arr[top][j]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", arr[i][right]);
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--)
                printf("%d ", arr[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--)
                printf("%d ", arr[i][left]);
            left++;
        }
    }
    printf("\n");

    return 0;
}
