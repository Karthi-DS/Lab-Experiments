#include <stdio.h>

void main(){
    int n,i,first,second,element;
    first = second = -1000;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to see its pos: \n");
    scanf("%d",&element);
    for(i=0;i<n;i++){
        if(arr[i]==element){
            printf("The position of entered element is %d",i+1);
            return;
        }
    }
    printf("The entered element is not in the array");
    return;
}

