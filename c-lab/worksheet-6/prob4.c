#include <stdio.h>
#include <limits.h>

int main(){
    int n,i,j,highest=0,lowest=INT_MAX;
    printf("Enter the number of attendance\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the attendance\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>highest){
            highest = arr[i];
        }
        if(arr[i]<lowest){
            lowest = arr[i];
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    printf("The highest attendance is %d\n",highest);
    printf("The lowest attendance is %d\n",lowest);
    printf("Sorted : [");

    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1<n){
            printf(",");
        }else{
            printf("]");
        }
    }
    return 0;
}
