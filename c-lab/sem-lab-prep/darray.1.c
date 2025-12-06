#include <stdio.h>
#include <stdlib.h>

void columnTotal(int** a,int m,int n){
    int i,j;
    int new_n = n+1;
    printf("resizing...\n");
    for(i=0;i<m;i++){
        a[i] = realloc(a[i],(new_n) * sizeof(int));
    }
    for(i=0;i<m;i++){
        int num =0;
        for(j=0;j<n;j++){
            num+=a[i][j];
        }
        a[i][j] = num;
    }
    printf("Elements are: \n");
    for(i=0;i<m;i++){
        for(j=0;j<new_n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int** a;
    int m,n,i,j;

    printf("Enter the no of rows and columns\n");
    scanf("%d %d",&m,&n);

    a = (int**)malloc(m*sizeof(int*));

    //columns
    for(i=0;i<m;i++){
        a[i] = (int*)malloc(n*sizeof(int));
    }

    //inputting from users
    printf("Enter the elements: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Elements are: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    columnTotal(a,m,n);
}


