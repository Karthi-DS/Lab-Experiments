#include <stdio.h>

void main(){
    int n,i,j,flag=1;
    printf("Enter the no of rows or columns\n");
    scanf("%d",&n);
    int matrix[n][n],symmetric[n][n],skew[n][n],transpose[n][n];

    printf("Enter the values: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            transpose[j][i] = matrix[i][j];
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            symmetric[i][j] = (matrix[i][j] + transpose[i][j])/2;
            skew[i][j] = (matrix[i][j] - transpose[i][j])/2;
            if(matrix[i][j]!=(symmetric[i][j] + skew[i][j])){
                flag=0;
            }
        }
    }

    printf("The matrix, skew , symmetric are\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d, ",matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d, ",symmetric[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d, ",skew[i][j]);
        }
        printf("\n");
    }

    if(flag){
        printf("It satisfies the condition of matrix = symmetric + skew\n");
    }
}