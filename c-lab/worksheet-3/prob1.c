#include <stdio.h>

void main(){
    int n,i,first,second;
    first = second = -1000;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>first){
            second = first;
            first = arr[i];
        }
    }
    printf("The Second largest element is %d ",second);
}











