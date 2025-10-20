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

int push(Stack *s,int ele){
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
    printf("The element %d is pushed\n",ele);
    s->arr[++s->top] = ele;
    }
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return 0;}
    printf("The element %d is popped\n",s->arr[s->top]);
    return s->arr[s->top--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty");
        return 0;}
    printf("The element %d is at top\n",s->arr[s->top]);
    return s->arr[s->top];
}

int isContinue(){
    char isCont;
    while(getchar()!='\n');
    printf("Do you want to continue: ");
    scanf("%c",&isCont);
    if(isCont=='y'){
        return 1;
    }
    return 0;
}

int showMenu(){
    int menu;
    printf("Menu functions : \n\t 1.push\n\t 2.pop \n\t 3.peek\n");
    printf("Enter menu: ");
    scanf("%d",&menu);
    return menu;
}


int main(){
    Stack s;
    init(&s);
    int menu;
    do{
    menu = showMenu();
    if(menu == 1){
    int ele;
    printf("Enter the element\n");
    scanf("%d",&ele);
    push(&s,ele);
    }
    else if ( menu == 2){
    pop(&s);
    }
    else{
    peek(&s);
    }}
    while(isContinue());

}
