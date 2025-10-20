
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int l=0,r,len;
    
    printf("Enter a Text: ");
    fgets(str, sizeof(str),stdin);
    len = strlen(str);
    str[len-1]='\0';
    
    r = len-2;

    while (r>l){
        if(str[l]==str[r]){
            l++;
            r--;
        }
        else{
            printf("Entered word is not a palindrome");
            return 0;
        }
    }
    
    printf("Entered word is a palindrome");

    return 0;
}