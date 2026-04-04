#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
} cll;


cll* createNode(int val){
    cll* newNode = malloc(sizeof(cll));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void addNode(cll** head,int val){
    cll* newNode = createNode(val);
    if(*head==NULL){
        *head = newNode;
        (*head)->next = newNode;
        return;
    }
    cll* tmp = *head;

    while(tmp->next!=*head){
        tmp=tmp->next;
    }

    tmp->next = newNode;
    newNode->next = *head;
    printf("Node added successfully...\n");
}

void deleteAtPos(cll** head, int pos){
    cll* tmp = *head;
    if(pos == 1){
        if(tmp->next == *head){
            free(tmp);
            printf("Head is deleted and list is empty\n");
        }else{
            tmp=tmp->next;
            while(tmp->next!=*head){
                tmp = tmp->next;
            }
            tmp->next = (*head)->next;
            free(*head);
            *head = tmp;
        }
    }else{
        cll* prev = NULL;
        while(tmp->next!=*head && (--pos)>0){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
    }
}

void printCll(cll* head){
    printf("%d->",head->val);
    cll* tmp = head->next;
    while(tmp!=head){
        printf("%d->",tmp->val);
        tmp = tmp->next;
    }
}


void main(){
    cll* head = NULL;
    addNode(&head,2);
    addNode(&head,4);
    addNode(&head,5);
    addNode(&head,6);
    deleteAtPos(&head,1);
    printCll(head);
}



