#include <stdio.h>
#define max 100

typedef struct{
    int arr[max];
    int front;
    int rear;
} queue;

void init(queue *q){
    q->front = q->rear = -1;
}

int isEmpty(queue *q){
    return q->front==q->rear;
}

int isFull(queue *q){
    return q->rear==max-1;
}

void enqueue(queue *q,int ele,int isPrintNeeded){
    if(isFull(q)){
        printf("queue is full");
    }else{
        q->arr[++q->rear] = ele;
        if(isPrintNeeded){
        printf("The element %d is inserted successfully\n",ele);
        }
    }
}

int dequeue(queue *q,int isPrintNeeded){
    if(isEmpty(q)){
        printf("queue is empty");
    }else{
        if(isPrintNeeded){
        printf("Element %d is deleted\n", q->arr[q->front+1]);
        }
        return q->arr[++q->front];
    }
}

void peek(queue *q){
    if(isEmpty(q)){
        printf("queue is empty");
    }else{
        printf("The element is at top %d\n",q->arr[q->front+1]);
    }
}


void pushQTS(queue *q1,int ele){
    enqueue(q1,ele,1);
}

int popQTS(queue *q1, queue *q2){
    if(isEmpty(q1) && isEmpty(q2)){
        printf("Stack is empty");
        return -1;
    }
    if(isEmpty(q2)){
        while(q1->rear-q1->front>1){
            enqueue(q2,dequeue(q1,0),0);
        }
    }
    return dequeue(q1,1);
}

void peekQTS(queue *q1, queue *q2){
    if(isEmpty(q1) && isEmpty(q2)){
        printf("Stack is empty");
    }
    if(isEmpty(q2)){
        while(q1->rear - q1->front > 1){
            enqueue(q2, dequeue(q1, 0), 0);
        }
    }
    peek(q1);
}


void main(){
    queue q1;
    queue q2;
    init(&q1);
    init(&q2);
    pushQTS(&q1,2);
    pushQTS(&q1,5);
    pushQTS(&q1,10);

    peekQTS(&q1,&q2);
}