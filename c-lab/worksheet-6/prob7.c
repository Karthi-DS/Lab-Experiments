#include <stdio.h>
#include <limits.h>

int main(){
    int n,i,l=0,r=0,profitL,profitR,profit = -INT_MAX;
    printf("Enter the number of shares\n");
    scanf("%d",&n);
    int arr[n];
    int tmp[n];
    printf("Enter the stocks\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        tmp[i] = arr[i];
    }
    while(r<n){
        if(arr[l]>arr[r]){
            l=r;
        }else{
            int tmpProfit = arr[r]-arr[l];
            if(profit<tmpProfit){
               profit = tmpProfit;
               profitL = l;
               profitR = r;
            }else{
               profit = profit;
            }
        }
        r++;
    }
    printf("The maximum profit is obtained by when stock bought at %d min and sold at %d min and the profit is :\n",profitL+1,profitR+1);
    printf("%d",profit);

    return 0;
}