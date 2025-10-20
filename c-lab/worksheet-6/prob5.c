#include <stdio.h>
#include <limits.h>

int main(){
    int n,i,j,highest=0,freq,thres;
    printf("Enter the threshold\n");
    scanf("%d",&thres);
    printf("Enter the number of scores\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the scores\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>highest){
            highest = arr[i];
        }
        if(arr[i]>thres){
            freq++;
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
    printf("The scores that are above threshold is %d\n",freq);
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