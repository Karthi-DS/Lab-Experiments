#include <stdio.h>
#include <string.h>

int isWordsIsomorphic(char *w,char *s){
    int res[256] ={0},tmpAsciS=0;
    char *token = strtok(s," ");
    char tmp[100],tmpl;
    for(int i =0;i<strlen(w);i++){
        tmpl = w[i];
        int j =0;
        for(int i=0;i<strlen(token);i++){
            j++;
            tmpAsciS += j*token[i];
        }
        printf("%d\n",tmpAsciS);
        if(res[tmpl]!=0 && tmpAsciS!=res[tmpl]){
            return 0;
        }
        res[tmpl] = tmpAsciS;
        tmpAsciS = 0;
        token = strtok(NULL," ");
    }
    return 1;
}
void main()
{
    char word[100];
    char sen[1000];
    int res;
    
    printf("Enter word: ");
    fgets(word,sizeof(word),stdin);
    printf("Enter sentence: ");
    fgets(sen,sizeof(sen),stdin);
    
    word[strcspn(word, "\n")] = '\0';
    sen[strcspn(sen, "\n")] = '\0';
    res = isWordsIsomorphic(word,sen);
    printf("%d",res);
    if(res){
        printf("it is ismorphic sentence");
    }else{
        printf("It is not isomorphic sentence");
    }
    
}