#include <stdio.h>
#include <math.h>

int main() {
    int n,x,i;
    long long res=1;
    printf("Enter the number to be multiplied: ");
    scanf("%d",&x);
    printf("Enter the number of times: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        res *= x; 
    }
    printf("The result is %lld",res);
    return 0;
}
