#include <stdio.h>

void display(int* a,int n){
    printf("displaying...\n");

    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
    printf("\n");
}

void bubbleSort(int* a,int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            if(a[j-1]>a[j]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void insertionSort(int* a,int n){
    for(int i=1; i<n; i++){
        int tmp = a[i];
        int j = i;

        while(j>0 && a[j-1]>tmp){
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}

void selectionSort(int* a,int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIndex]){
                minIndex = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = tmp;
    }
}

int binarySearch(int* a,int n,int s){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]>s){
            r = mid-1;
        }
        else if(a[mid]<s){
            l = mid+1;
        }else{
            return mid;
        }
    }
}

void main(){
    int arr[] = {7,2,3,1,0,10,9};
    selectionSort(arr,7);
    display(arr,7);
    int index = binarySearch(arr,7,10);
    printf("Binary search index: %d\n",index);
}
