#include <stdio.h>

void main(){
    int m,n,count=0,ele,i,j,validator;
    printf("Enter the number of rows to be in array: ");
    scanf("%d",&m);
    printf("Enter the number of columns to be in array: ");
    scanf("%d",&n);
    int arr[m][n];
    validator = (m*n)/2;
    printf("Enter elements of the array:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&ele);
            arr[i][j] = ele;
            if(ele==0){
                count++;
            }
        }
    }
    if(validator>count){
        printf("It is not a Sparse matrix");
    }else{
        printf("It is a Sparse matrix");
    }
}



