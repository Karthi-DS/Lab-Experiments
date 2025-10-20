#include <stdio.h>
#include <stdlib.h>


void main(){
    int n,i,k,j,avg;
    printf("How many elements in array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the distance to find average: \n");
    scanf("%d",&k);
    if(k>n){
        printf("Distance should be less than array length.");
        return;
    }else{
        for(i=0;i+k<n;i++){
            int sum = 0;
            for(j=i;j<=(i+k);j++){
                sum+=arr[j];
            }
            if(avg<(sum/k)){
                avg = (sum/k);
            }
        }
        printf("The max avg is %d",avg);
        return;
    }
}


