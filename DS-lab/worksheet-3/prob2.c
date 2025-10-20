#include <stdio.h>


void main(){
int m,n,count=0,ele,i,j,total;
    printf("Enter the number of rows to be in array: ");
    scanf("%d",&m);
    printf("Enter the number of columns to be in array: ");
    scanf("%d",&n);
    int arr[m][n];
    printf("Enter elements of the array:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&ele);
            arr[i][j] = ele;
        }
    }
    total = arr[0][0]+arr[0][n-1]+arr[m-1][0]+arr[m-1][n-1];
    printf("The corner elements are : %d, %d ,%d ,%d, and it's sum is %d",arr[0][0],arr[0][n-1],arr[m-1][0],arr[m-1][n-1],total);
    }
