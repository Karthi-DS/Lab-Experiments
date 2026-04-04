#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[20];
    struct node* next;
} ll;


ll* createNode(char* w){
    ll* newNode = (ll*)malloc(sizeof(ll));
    strcpy(newNode->word,w);
    newNode->next = NULL;
    return newNode;
}

void addNode(ll** head, char* w){
    ll* tmp = *head;
    ll* newNode = createNode(w);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return;
}

ll* pop(ll** head){
    ll* tmp = *head;
    ll* prev = NULL;
    if(tmp==NULL){
        printf("Linked List is empty.");
        return tmp;
    }
    while(tmp->next!=NULL){
        prev = tmp;
        tmp = tmp->next;
    }
    printf("Node with value: %s is popped",tmp->word);
    prev->next = NULL;
    free(tmp);
}

void peek(ll* head){
    if(head==NULL){
        printf("Linked List is empty.");
        return;
    }
    while(head->next!=NULL){
        head = head->next;
    }
    printf("Node with value: %s\n",head->word);
}

ll* printFromTop(ll* head){
    if(head==NULL){
        return head;
    }
    printFromTop(head->next);
    printf("%s->",head->word);
}

void print(ll* head){
    while(head!=NULL){
        printf("%s",head->word);
        head = head->next;
    }
    printf("\n");
}

void main(){
    ll* head = NULL;
    addNode(&head,"I ");
    addNode(&head,"am ");
    addNode(&head,"Karthi ");
    addNode(&head,"from ");
    addNode(&head,"psg.");
    peek(head);
    print(head);
    pop(&head);
    printFromTop(head);
}
