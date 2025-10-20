#include <stdio.h>
#include <string.h>

void main(){
    int n,max,min,maxId,minId,flag=1;
    long int checkAmount;
    long long int total=0;
    char id[5][50],decision[3];
    printf("Enter the number of sales\n");
    scanf("%d",&n);
    long salesAmount[n];
    max = 0;
    min = 0;
    printf("Enter the name and sales amount of each salesman\n");

    for(int i =0;i<n;i++){
        printf("Enter the person name for ID\n");
        scanf("%s",id[i]);
        printf("enter the amount\n");
        scanf("%ld",&salesAmount[i]);
        total+=salesAmount[i];
        if(salesAmount[i]>max){
            max = salesAmount[i];
            maxId = i;
        }
        if(salesAmount[i]<min){
            min = salesAmount[i];
            minId = i;
        }
    }

    printf("The average sales amount is %lld\n", (total/n));

    printf("The maximum sale recorded for %s and the amount is %d\n",id[maxId],salesAmount[maxId]);
    printf("The minimum sale recorded for %s and the amount is %d\n",id[minId],salesAmount[minId]);

    printf("Would you like to check the sales that exceeds the amount you enter?\n yes or no:\n ");
    scanf("%s",decision);
    printf("Enter the amount: ");
    scanf("%ld",&checkAmount);
    if(strcmp(decision,"yes")==0){
        for(int i =0;i<n;i++){
            if(salesAmount[i]>checkAmount){
                flag = 0;
                printf("The sale recorded for %s and the amount is %d\n",id[i],salesAmount[i]);
            }
        }
    }
    if(flag)
        printf("No sales has exceeded more than the exceeded amount.\n");
}










