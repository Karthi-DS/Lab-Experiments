#include <stdio.h>

void main(){
    int i,n,j;
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);
    int nums[n];
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(nums[j]<nums[j+1]){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    printf("The Second largest element in the entered list is %d",nums[1]);
}












