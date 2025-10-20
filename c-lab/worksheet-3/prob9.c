#include <stdio.h>

void main(){
    int n1,n2,i;
    printf("Enter the no of elements of array 1: \n");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter the elements of array 1: \n");
    for(i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the no of elements of array 2: \n");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter the elements of array 2: \n");
    for(i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    int arr1_2[n1+n2],j=0;
    i=0;
    while(i<n1&&j<n2){
        if(arr1[i]<arr2[j]){
            arr1_2[i+j] = arr1[i];
            i++;
        }else{
            arr1_2[i+j] = arr2[j];
            j++;
        }
    }
    printf("i: %d,j: %d",i,j);
    while(j<n2){
        arr1_2[i+j] = arr2[j];
        j++;
    }
    while(i<n1){
        arr1_2[i+j] = arr1[i];
        i++;
    }
    printf("The Sorted elements are: \n");
    for(int i=0;i<(n1+n2);i++){
        printf("%d\n",arr1_2[i]);
    }
    return;
}
