#include <stdio.h>
#include <string.h>

void main(){
    int i,n,j;
    char arr[20];
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);
    int nums[n];
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("Enter ascending or descending: ");
    scanf("%s",arr);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if((strcmp(arr, "descending") == 0)){
                if(nums[j]<nums[j+1]){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
            }else if((strcmp(arr, "ascending") == 0)){
                if(nums[j]>nums[j+1]){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
            }
            else{
                printf("invalid input");
            }
        }
    }
    printf("The sorted elements are: \n");
    for(i=0;i<n;i++){
        printf("%d\n",nums[i]);
    }
}
