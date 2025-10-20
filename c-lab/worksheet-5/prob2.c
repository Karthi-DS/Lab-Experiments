#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void askQuestion(){
    int n,ans,grade=0;
    char key[100];
    printf("Enter the number of questions: ");
    scanf("%d",&n);
    getchar();
    printf("Enter the answer key in single line: ");
    fgets(key,sizeof(key),stdin);
    char *token = strtok(key," ");
    while(token!=NULL){
        printf("Enter answer: ");
        scanf("%d",&ans);
        int numAns = atoi(token);
        if(numAns == ans){
            grade++;
        }
        token = strtok(NULL," ");
    }
    printf("The no of questions is %d and you correctly entered was %d\n",n,grade);
}

void main(){
    char isContinue;
    while(1){
        askQuestion();
        printf("Do you want to continue y(yes) or n(no)\n");
        scanf(" %c",&isContinue);
        if(isContinue == 'n'){
            break;
        }
    }
}
