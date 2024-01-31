#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow!\n");
        return -1;
    }
    return queue[front++];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    enqueue(40);

    printf("Dequeued element: %d\n", dequeue());

    return 0;
}
