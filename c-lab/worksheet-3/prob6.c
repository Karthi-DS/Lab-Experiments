#include <stdio.h>

void main(){
    int n,i,l,r,tmp;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    l=0;
    r=n-1;
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
    printf("The array is reversed in place");
    for(i=0;i<n;i++){
        printf("\n%d",arr[i]);
    }
    return;
}

