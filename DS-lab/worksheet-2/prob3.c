#include <stdio.h>
#include <string.h>

void main(){
    int arr[30] = {2,3,5,1,6,7,8,10,4,11,12,26,15,17,18,19,20,21,22,23,26,27,28,30},num,i;
    printf("The array consists of 1 to 30 at random positions enter number (1 to 30)\n to find its position: ");
    scanf("%d",&num);
    for(i=0;i<29;i++){
        if(arr[i]==num){
            printf("The number %d is at the position of %d",num,i+1);
        }
    }
}