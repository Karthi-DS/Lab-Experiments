#include <stdio.h>

int main(){
    int n,i,j,highest=0,total=0;
    float avg;
    printf("Enter the number of marks\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the marks\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>highest){
            highest = arr[i];
        }
        total+=arr[i];
    }
    avg = (float)total/(float)n;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    printf("The highest mark is %d\n",highest);
    printf("The average mark is %.2f\n",avg);
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