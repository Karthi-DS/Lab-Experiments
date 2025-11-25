#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct student{
    char name[20];
    char date[10];
    int wpd;
    int salary;
} stu;

void display(stu* s){
    for(int i=0; i<10;i++){
        printf("------------------\n");
        printf("Name: %s\n",s[i].name);
        printf("Date: %s\n",s[i].date);
        printf("Work Per Day: %d\n",s[i].wpd);
        printf("Salary: %d\n",s[i].salary);
        printf("------------------\n");
    }
}

int getExp(char* date){
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char* token = strtok(date,"/");
    char* last;
    while(token!=NULL){
        last = token;
        token = strtok(NULL,"/");
    }
    int joinYear = atoi(last);
    int currentYear = t->tm_year+1900;
    return (currentYear-joinYear);
}

void increaseSalary(stu* s){
    for(int i=0;i<10;i++){
        stu curr = s[i];
        int exp = getExp(curr.date);
        if(exp<5 && curr.wpd==8){
            s[i].salary += 50;
        }else if(exp>=5&&exp<10 && curr.wpd==10){
            s[i].salary += 100;
        }else if(exp>=10 && curr.wpd==12){
            s[i].salary += 150;
        }else{
            continue;
        }
    }
}


void main(){
     stu s[10] = {
        {"Arun",     "01/01/2021", 8, 15000},
        {"Karthi",   "12/02/2001", 4, 18000},
        {"Priya",    "23/03/2003", 6, 20000},
        {"Ravi",     "14/04/2002", 3, 12000},
        {"Sneha",    "05/05/2001", 7, 22000},
        {"Vijay",    "16/06/2000", 2, 10000},
        {"Anitha",   "27/07/2003", 5, 17000},
        {"Rahul",    "08/08/2002", 12, 21000},
        {"Divya",    "19/09/2001", 12, 16000},
        {"Suresh",   "30/10/2000", 12, 25000}
    };
    printf("Before increase salary\n");
    display(s);
    increaseSalary(s);
    printf("After increase salary\n");
    display(s);
}
