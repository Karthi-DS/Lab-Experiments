#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void writeIntoFile(FILE* fp){
    char d[100];
    if(fp==NULL){
       printf("File not found");
    }
    printf("Enter data: \n");
    fgets(d,sizeof(d),stdin);
    printf("written into the file. \n");
    fputs(d,fp);
}

void getSpecificLine(FILE* fp,int line){
    int count = 0;
    char d[100][256];
    while(fgets(d[count],sizeof(d[count]), fp)){
        count++;
    }
    printf("%s",d[line]);
}

void modifySpecificLine(FILE* fp,int line){
    int count = 0;
    char d[100][256];
    char m[256];
    rewind(fp);
    while(fgets(d[count],sizeof(d[count]), fp)){
        count++;
    }
     // Clear leftover input
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    printf("Enter data: \n");
    //modifying...
    fgets(m,sizeof(m),stdin);
    strcpy(d[line],m);

    //rewinding fp
    rewind(fp);
    for(int i =0;i<count;i++){
        fputs(d[i],fp);
    }
    printf("modified data... \n");
}

void main(){
    FILE* fp;
    fp = fopen("log.txt","r+");
    getSpecificLine(fp,1);
    modifySpecificLine(fp,1);
}
