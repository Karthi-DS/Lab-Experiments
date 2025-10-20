#include <stdio.h>

int main()
{
    int n,k,i,j;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the distance k: \n");
    scanf("%d",&k);
    for(i=0;i<n;i++){
        int tmpK = k;
        for(j=i;i<n;j++){
            if(tmpK>0 && arr[i]!=arr[j]){
                tmpK--;
            }
            else if(tmpK>0 && arr[i]==arr[j]){
                printf("The element %d is repeated within K distance",arr[i]);
                return 1;
            }else{
                break;
            }
        }
    }
    return 0;
}