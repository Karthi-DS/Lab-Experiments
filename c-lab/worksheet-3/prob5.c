#include <stdio.h>

void main(){
    int n,i,j;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=n;i<=0;i--){
        if(arr[i]==arr[j]){
            printf("This array has duplicate %d",arr[i]);
            return;
        }
    }
    printf("The entered array doesn't have any duplicates");
    return;
}
