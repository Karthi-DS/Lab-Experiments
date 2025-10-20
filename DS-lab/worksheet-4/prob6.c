#include <stdio.h>

int main()
{
    int arr[] = {2,-1,0,-30,-3,20,100,-4},l,r,len;
    l = 0;
    len = (sizeof(arr)/sizeof(arr[0]));
    int res[len];
    r = len - 1;
    for(int i =0;i<len;i++){
        if(arr[i]>=0){
            res[l] = arr[i];
            l++;
        }else{
            res[r] = arr[i];
            r--;
        }
    }
    
    for(int i=0;i<len;i++){
        printf("%d\n",res[i]);
    }

    return 0;
}