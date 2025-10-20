#include <stdio.h>
#include <stdlib.h>

void main(){
    int n,i;
    printf("How many elements in array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(abs(arr[i]-arr[i+1])==1){
            printf("The position of the elements are %d, %d",i+1,i+2);
            return;
        }
    }
    printf("No adjacent elements found with difference 1");
    return;
    
}
