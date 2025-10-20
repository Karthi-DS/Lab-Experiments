#include <stdio.h>
#include <string.h>

int isAnagram(char *a, char *b)
{
    int count[256] = {},i;
    
    
    if(strlen(a)!=strlen(b)){
        return 0;
    }
    for(i=0;i<strlen(a);i++){
        char c = a[i],d =b[i];
        count[c] +=1;
        count[d] -=1;
    }
    for(i=0;i<256;i++){
        if(count[i]!=0){
            return 0;
        }
    }
    return 1;
}

void main(){
    char a[100],b[100];
    printf("Enter first word: ");
    fgets(a,sizeof(a),stdin);
    printf("Enter second word: ");
    fgets(b,sizeof(b),stdin);
    int res = isAnagram(a,b);
    if(res){
        printf("It is Anagram");
    }else{
        printf("It is not Anagram");
    }
}
