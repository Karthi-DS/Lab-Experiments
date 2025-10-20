#include <stdio.h>

int main(){
    int n,g,i,freq;
    printf("Enter the number of days\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the types of gift\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the gift type to find\n");
    scanf("%d",&g);

    for(i=0;i<n;i++){
        if(arr[i]==g){
            freq++;
        }
    }
    if(freq>1){
        printf("The gift type %d is occurred %d times",g,freq);
    }else{
        printf("The gift types is not occurred a single time");
    }
    return 0;
}