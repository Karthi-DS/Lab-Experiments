#include <stdio.h>
#include <string.h>

int solution(char* str){
    int count[1024] = {0};
    int res = 0,toggled =0,mask=0;
    int len = strlen(str);
    count[0] = 1;
    for(int i=0;i<len;i++){
        char c = str[i];
        mask^=1<<(c-'a');
        res+=count[mask];

        for(int i=0;i<10;i++){
            toggled = mask^(1<<i);
            res+=count[toggled];
        }

        count[mask]++;
    }
    return res;
}


void main(){
    char ch[100];
    printf("Enter the string: ");
    scanf("%s",&ch);
    int res = solution(ch);
    printf("%d",res);
}
