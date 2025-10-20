#include <stdio.h>
#define max 100

typedef struct{
    int arr[max];
    int front;
    int rear;
} Queve;

void init(Queve *q){
    q->front = q->rear = -1;
}

int isEmpty(Queve *q){
    return q->front==q->rear;
}

int isFull(Queve *q){
    return q->rear==max-1;
}

void enqueve(Queve *q,int ele){
    if(isFull(q)){
        printf("Queve is full");
    }else{
        q->arr[++q->rear] = ele;
        printf("The element %d is inserted successfully\n",ele);
    }
}

void dequeve(Queve *q){
    if(isEmpty(q)){
        printf("Queve is empty");
    }else{
        printf("Element %d is deleted\n", q->arr[q->front++]);
    }
}

void peek(Queve *q){
    if(isEmpty(q)){
        printf("Queve is empty");
    }else{
        printf("The element is at top %d\n",q->arr[q->front+1]);
    }
}
