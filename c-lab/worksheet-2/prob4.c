
#include <stdio.h>

void main(){
int num,sum=0,mul=1,rem;
printf("Enter number: ");
scanf("%d",&num);
if(num>0){
    while(num>0){
        rem = num%10;
        sum+=rem;
        mul*=rem;
        num /=10;
    }
    if(sum==mul){
        printf("The sum of digits is equal to product of digits");
    }else{
        printf("The sum of digits is not equal to product of digits");
    }
}else{
    printf("Entered number is invalid");
}
}

