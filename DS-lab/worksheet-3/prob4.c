#include <stdio.h>
#include <string.h>

void main(){
    char input[100], res[50]="";
    int i,j=0;
    printf("Enter the decoded word: ");
    scanf("%s",input);

    for(i=0;j<strlen(input);i++){
        if(input[i]=='b'){
            continue;
        }else if(input[i]=='a'&&input[i+1]=='c'){
            i++;
            continue;
        }else{
            res[j] = input[i];
            j++;
        }
    }
    printf("The decoded value is %s",res);
}
