#include <stdio.h>

void main(){
    int n,i,j,k,f=0;
    printf("Enter the no of elements of array: \n");
    scanf("%d",&n);
    int arr[n];
    int freqElements[n];
    printf("Enter the elements of array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the kth term: \n");
    scanf("%d",&k);
    for(i=0;i<n;i++){
                    int count = 0;

            for(j=i;j<n;j++){
        if(arr[i]==arr[j]){
            count++;
            if(count>(int)n/k && freqElements[f-1]!=arr[i]){
                freqElements[f] = arr[i];
                f++;
            }
        }
    }}
    if(f>0){
        printf("The element that repeated n/k times are :\n");
        for(i=0;i<f;i++){
            printf("%d\n",freqElements[i]);
        }
        return;
    }
    printf("There is no element that repeated n/k times");
    return;
}
