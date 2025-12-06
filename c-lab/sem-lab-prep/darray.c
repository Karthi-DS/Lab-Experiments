#include <stdio.h>
#include <stdlib.h>


void main(){
    int** a;
    int m,n,i,j;
    printf("Enter rows and columns\n");
    scanf("%d %d",&m,&n);
    getchar();

    //row malloc
    a = (int**)malloc(m*sizeof(int*));
    //column malloc
    for(i=0;i<m;i++){
        a[i] = (int*)malloc(n*sizeof(int));
    }

    //inputing the array from user
    printf("Enter the array elements \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("The array elements are: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    a = realloc(a,++m * sizeof(int*));
    a[m-1] = (int*)malloc(n*sizeof(int));
    int b = m-1;
    int num = 0;
    for(i=0;i<n;i++){
        num = 0;
        for(j=0;j<m-1;j++){
            num+=a[j][i];
        }
        a[b][i] = num;
    }

    printf("The array elements are: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
