#include <stdio.h>
#include <math.h>


void main(){
    float x,y;
    int radius,isValid;
    printf("Enter X and Y\n");
    scanf("%f%f",&x,&y);
    printf("Enter radius\n");
    scanf("%d",&radius);
    isValid = ((pow(x,2)+pow(y,2))<pow(radius,2));
    printf("%d",isValid);
    if(isValid){
        printf("It lies inside coordinates");
    }else{
        printf("It lies outside coordinates");
    }
}
