#include <stdio.h>
#include <string.h>


int solution(char s[]){
    int count[1024] = {0};
    int mask = 0,toggled = 0,result =0;
    count[0] = 1;
    for(int i=0;i<strlen(s);i++){
        char c = s[i];
        mask ^= 1<<(c-'a');
        result += count[mask];


        for(int i=0;i<10;i++){
            toggled = mask^(1<<i);
            result+=count[toggled];
        }


        count[mask]++;
    }
    return result;
}


void main(){
    char ch[100];
    printf("Enter the string: ");
    scanf("%s",&ch);
    int res = solution(ch);
    printf("%d",res);
}
