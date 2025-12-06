#include <stdio.h>
#include <stdlib.h>


void display(int** a,int m,int n){
    printf("printing... \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}

void main(){
    int** a;
    int m,n,i,j;

    printf("Enter rows and columns: \n");
    scanf("%d %d",&m,&n);

    a = (int**)malloc(m*sizeof(int*));

    for(i=0;i<m;i++){
        a[i] = (int*)malloc(n*sizeof(int*));
    }

    //inputting
    printf("Enter elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    display(a,m,n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(j>i){
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }

    display(a,m,n);

    for(i=0;i<m;i++){
        for(j=0;j<n/2;j++){
                int temp = a[i][j];
                a[i][j] = a[i][n-j-1];
                a[i][n-j-1] = temp;
        }
    }

    display(a,m,n);
}
