#include <stdio.h>
#define MAX 100

typedef struct{
    int arr[MAX];
    int top;
} Stack;
void init(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}

int isFull(Stack *s){
    return s->top==MAX-1;
}

int push(Stack *s,int ele,int isPrintNeeded){
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
        if(isPrintNeeded){
            printf("The element %d is pushed\n",ele);
        }
    s->arr[++s->top] = ele;
    }
}

int pop(Stack *s,int isPrintNeeded){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return 0;}
    if(isPrintNeeded){
        printf("The element %d is popped\n",s->arr[s->top]);
    }
    return s->arr[s->top--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty");
        return 0;}
    printf("The element %d is at top\n",s->arr[s->top]);
    return s->arr[s->top];
}


void enqueueSTQ(Stack *s1,int ele){
    push(s1,ele,1);
}

int dequeueSTQ(Stack *s1, Stack *s2){
    if(isEmpty(s1)){
        printf("Queue is Empty");
        return;
    }
    if(isEmpty(s2)){
        while(!isEmpty(s1)){
            push(s2,pop(s1,0),0);
        }
    }
    return pop(s2,1);
}

int peekSTQ(Stack *s1, Stack *s2){
    if(isEmpty(s1)){
        printf("Queue is Empty");
        return;
    }
    if(isEmpty(s2)){
        while(!isEmpty(s1)){
            push(s2,pop(s1,0),0);
        }
    }
    return peek(s2);
}


void main(){
    Stack s1;
    Stack s2;
    init(&s1);
    init(&s2);
    enqueueSTQ(&s1,3);
    enqueueSTQ(&s1,4);
    enqueueSTQ(&s1,5);
    enqueueSTQ(&s1,6);
    dequeueSTQ(&s1,&s2);
}