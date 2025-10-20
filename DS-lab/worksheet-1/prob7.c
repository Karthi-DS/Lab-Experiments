// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>


int main() {
    int length,maxlength=0,j,l,isUnique;
    char *words[] = {"abqw","hjkhkj","ui","ertuio","mnhkophkju"};
    length = sizeof(words)/sizeof(words[0]);
    for(j=0;j<length;j++){
        
        for(l=j+1;l<length;l++){
            isUnique=1;
            int arr[256] = {0};
        for(int r =0;r<strlen(words[j]);r++){
            arr[words[j][r]] =1;
        }
            for(int c=0;c<strlen(words[l]);c++){
                if(arr[words[l][c]]!=0){
                    isUnique=0;
                    break;
                }         
            }
            if(isUnique){
                int product = strlen(words[j])*strlen(words[l]);
                if(maxlength<product){
                    maxlength = product;
                }
            }
        }
    }
    if(maxlength>0){
        printf("The max length of unique words %d",maxlength);
        return 1;
    }
    printf("No two unique words found");
    return 0;
}