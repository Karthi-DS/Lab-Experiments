#include <stdio.h>

void main(){
    int m,n,k,count=0,p,res=1;
    printf("Enter three positive integers n, m, k: ");
    scanf("%d %d %d", &n, &m, &k);

    for(p = k;p>=1;p--){
        if(m%p==0 && n%p==0){
            count++;
            if(count==3){
                res = p;
            }
        }
    }
    printf("result : %d\n", res);
    return 0;
}