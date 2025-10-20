#include <stdio.h>

void main(){
    int i,j=0,n,k;
    printf("enter no of elements: ");
    scanf("%d",&j);
    printf("Enter elements: \n");
    int arr[j],res[j];
    for(i=0;i<j;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter no of elements to skip: ");
    scanf("%d",&n);
    k=0;
    for(i=0;i<j;i++){
        if(i+n<j){
        res[i] = arr[i+n];
        }else{
            res[i] = arr[k];
            k++;
        }
    }
    printf("The final array is : \n");
    for(i=0;i<j;i++){
        printf("%d\n",res[i]);
    }
}