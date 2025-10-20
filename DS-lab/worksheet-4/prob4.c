#include <stdio.h>

void merge(int arr[],int l,int r, int mid){
    int n1,n2,i,j,k;
    
    n1 = mid - l + 1;
    n2 = r - mid;
    
    int leftArr[n1];
    int rightArr[n2];
    
    for(i=0;i<n1;i++){
        leftArr[i] = arr[i+l];
    }
    for(j=0;j<n2;j++){
        rightArr[j] = arr[mid+j+1];
    }
    
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid = l + (r-l)/2;
        
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        
        merge(arr,l,r,mid);
    }
}

int main()
{
    int len,i,n,l,r,pos;
    printf("Enter no of elements to sort: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    len = sizeof(arr)/sizeof(arr[0]);
    l=0;
    r = len-1;
    mergesort(arr,l,r);
    printf("Enter the position: \n");
    scanf("%d",&pos);
    printf("The element is %d",arr[pos-1]);
    return 0;
}