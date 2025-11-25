#include <stdio.h>
#include <string.h>

int isIsomorphic(char *a, char *b)
{
    int mapa_b[256] = {},i;
    int mapb_a[256] = {};
    
    
    if(strlen(a)!=strlen(b)){
        return 0;
    }
    for(i=0;i<strlen(a);i++){
        char c = a[i],d =b[i];
    if(mapa_b[c] != 0 && mapa_b[c] != d){
        return 0;
    }
    if(mapb_a[d] != 0 && mapb_a[d]!=c){
        return 0;
    }
    mapa_b[c] = d;
    mapb_a[d] = c;
    }
    return 1;
}

void main(){
    char a[100],b[100];
    printf("Enter first word: ");
    fgets(a,sizeof(a),stdin);
    printf("Enter second word: ");
    fgets(b,sizeof(b),stdin);
    int res = isIsomorphic(a,b);
    if(res){
        printf("It is Isomorphic");
    }else{
        printf("It is not Isomorphic");
    }
}