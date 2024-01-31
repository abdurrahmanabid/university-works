#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to the stack.\n", item);
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    return 0;
}
