#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studInfo{
    int id;
    char name[50];
    char company[40];
    int salary;
    struct studInfo* next;
} stud;

stud* createNode(){
    int id,salary;
    printf("Enter Id and salary:\n");
    scanf("%d %d",&id,&salary);

    char name[100],company[100];
    printf("Enter your name:\n");
    scanf("%s",name);

    printf("Enter your company:\n");
    scanf("%s",company);

    stud* stu = (stud*)malloc(sizeof(stud));
    stu->id = id;
    strcpy(stu->name,name);
    strcpy(stu->company,company);
    stu->salary = salary;
    stu->next = NULL;
    return stu;
}

void addNode(stud** head){
    stud* newNode = createNode();
    if(*head==NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void display(stud* head){
    while(head!=NULL){
        printf("------------------\n");
        printf("Id : %d\n",head->id);
        printf("Name : %s\n",head->name);
        printf("Company : %s\n",head->company);
        printf("Salary : %d\n",head->salary);
        printf("------------------\n");
        head=head->next;
    }
}

void storeall(stud* head,FILE* fp){
    rewind(fp);

    while(head!=NULL){
        fprintf(fp,"Id: %d\nSalary: %d\nName: %s\nCompany: %s\n",head->id,head->salary,head->name,head->company);
        head=head->next;
    }
     printf("All student records stored into file.\n");
}



void modifySpecificLine(FILE* fp,int line){
    int count = 0;
    char data[100][256];
    char m[256];
    //getting data
    while(fgets(data[count], sizeof(data[count]), fp)){
        count++;
    }
    rewind(fp);
    //modifying data
    printf("Enter data:\n");
    fgets(m,sizeof(m),stdin);

    strcpy(data[line],m);

    //into file
    for(int i=0; i<count;i++){
        fputs(data[i],fp);
    }
}





void main(){
    FILE* fp;
    fp = fopen("log.txt","r+");

    stud* head = NULL;
    addNode(&head);
    addNode(&head);
    display(head);
    storeall(head,fp);
}
