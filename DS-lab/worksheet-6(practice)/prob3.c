#include <stdio.h>
#define max 3

typedef struct{
    int arr[max];
    int front;
    int rear;
} Queve;

void init(Queve *q){
    q->front = q->rear = -1;
}

int isEmpty(Queve *q){
    return q->front==-1;
}

int isFull(Queve *q){
    return (q->rear+1)%max==q->front;
}

void enqueve(Queve *q,int ele){
    if(isFull(q)){
        printf("Queve is full\n");
        return;
    }else if(q->rear==-1 && q->front==-1){
        q->rear = q->front =0;
    }else if(q->rear==max-1){
        q->rear=0;
    }else{
        q->rear++;
    }
    q->arr[q->rear] = ele;
}

void dequeve(Queve *q){
    if(isEmpty(q)){
        printf("Queve is empty\n");
        return;
    }else if(q->front==q->rear){
        q->rear = q->front =0;
    }else if(q->front==max-1){
        q->front=0;
    }else{
        printf("Element %d is deleted\n",q->arr[q->front]);
        q->front++;
    }
}

void peek(Queve *q){
    if(isEmpty(q)){
        printf("Queve is empty\n");
    }else{
        printf("The element is at top %d\n",q->arr[q->front]);
    }
}

void main(){
    Queve q;
    init(&q);
    enqueve(&q,3);
    enqueve(&q,4);
    enqueve(&q,10);
    dequeve(&q);
    enqueve(&q,11);
    enqueve(&q,11);
    peek(&q);
}