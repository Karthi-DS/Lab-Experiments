#include <stdio.h>

int isNotPrime(int n){
    int i,flag=0;
    for(i=2;i<n;i++){
        if(n%i==0){
            flag = 1;
        }
    }
    return flag;
}

void main(){
    int ele,i,j=0,res[5] = {0};
    printf("enter five elements:\n");
    for(i=0;i<5;i++){
        scanf("%d",&ele);
        if(isNotPrime(ele)){
            res[j] = ele;
            j++;
        }else{
            continue;
        }
    }
    printf("Elements of non-prime numbers:\n");
    for(i=0;i<=j;i++){
        printf("%d\n",res[i]);
    }

}
