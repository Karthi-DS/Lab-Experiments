#include <stdio.h>
#include <limits.h>

int main(){
    int n,i,j,highest=0,rank;
    printf("Enter the number of scores\n");
    scanf("%d",&n);
    int arr[n];
    int tmp[n];
    printf("Enter the scores\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        tmp[i] = arr[i];
        if(arr[i]>highest){
            highest = arr[i];
        }
    }
    int hash[highest];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    for(i=0;i<n;i++){
        hash[arr[i]-1] = i+1;
    }
    for(i=0;i<n;i++){
        int rank = hash[tmp[i]-1];
        tmp[i] = rank;
    }
    printf("Rank : [");
    for(i=0;i<n;i++){
        printf("%d",tmp[i]);
        if(i+1<n){
            printf(",");
        }else{
            printf("]");
        }
    }

    return 0;
}
