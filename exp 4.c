
#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;
void enqueue(int item) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    size++;
}
int dequeue() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    front = (front + 1) % MAX;
    size--;
    return item;
}
int frontElement() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}
int rearElement() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[rear];
}
void displayQueue() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    int count = size;
    while (count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;}
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    displayQueue();
    dequeue();
    displayQueue();
    printf("Front element: %d\n", frontElement());
    printf("Rear element: %d\n", rearElement());
    return 0;
}
