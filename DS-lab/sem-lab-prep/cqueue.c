#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
        return;
    }

    if (rear == -1) { // first insertion
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

// Dequeue operation
int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // full at this point

    display();

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    display();

    enqueue(60);
    enqueue(70);
     enqueue(60);
    enqueue(70);


    display();

    return 0;
}
