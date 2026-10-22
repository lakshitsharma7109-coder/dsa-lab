#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) return;

    n->data = x;

    if (rear == NULL) {
        rear = n;
        n->next = n;
    } else {
        n->next = rear->next;
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *front = rear->next;

    if (front == rear)
        rear = NULL;
    else
        rear->next = front->next;

    free(front);
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = rear->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();  // 10 20 30
    dequeue();
    display();  // 20 30

    return 0;
}