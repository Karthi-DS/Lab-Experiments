#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
   int n1,n2,i,j,k;
   n1 = mid-left+1;
   n2 = right-mid;
   int leftArr[n1];
   int rightArr[n2];
   for(i=0;i<n1;i++){
    leftArr[i] = arr[left+i];
   }
   for(j=0;j<n2;j++){
    rightArr[j] = arr[mid+1+j];
   }
   i = 0;
   j = 0;
   k = left;
   // reason why we choose left was we are sorting in ascending order
   while(i<n1 && j<n2){
    if(leftArr[i]<rightArr[j]){
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

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void main(){
    int n=0,i,j,count=0;
    printf("Enter the number of sections: ");
    scanf("%d",&n);
    int **sections = malloc(n*sizeof(int*));
    if(sections==NULL){
            printf("row allocation failed");
            return;
    }
    int *resultArray = malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        //initializing cols
        int cols;
        //getting no of cols for that id;
        printf("Enter the number of ids in this section %d:\n",i+1);
        scanf("%d",&cols);
        //reallocating the size of cols
        int *tmp = realloc(resultArray,(cols+count)*sizeof(int));
        sections[i] = malloc(cols*sizeof(int));
        //exception handling
        if(sections[i]==NULL){
            printf("column allocation failed");
            return;
        }
        printf("Enter the id of section %d: \n",i+1);
        for(j=0;j<cols;j++){
            scanf("%d",&sections[i][j]);
            getchar();
            int isDuplicate = 0;
            for(int k =0;k<count;k++){
                if(tmp[k]==sections[i][j]){
                    isDuplicate = 1;
                }
            }
            if(isDuplicate == 0){

            tmp[count] = sections[i][j];
            count++;
            }
        }
        resultArray = tmp;
    }
    mergeSort(resultArray,0,count-1);
    printf("Sorted section ids:\n");
    for(i=0;i<count;i++){
        printf("%d\n",resultArray[i]);
    }
}

