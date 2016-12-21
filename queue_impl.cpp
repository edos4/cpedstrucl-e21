#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int arr[MAX];
int front, rear;

bool isEmpty() {
  return (front == -1 && rear == -1) ? true : false;
}

bool isFull() {
  return (rear + 1) % MAX == front ? true : false;
}

void enQueue(int x) {
  if (isFull()) {
    printf("queue is full\n");
    return;
  }
  if (isEmpty())
    front = rear = 0;
  else
    rear = (rear + 1) % MAX;

  arr[rear] = x;
}

void deQueue() {
  if (isEmpty()) {
    printf("queue is empty\n");
    return;
  } else if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % MAX;
}

void Print() {
  int length = (rear + MAX - front) % MAX + 1;
  int i;
  for (i = 0; i < length; i++) {
    printf("%d ", arr[(front + i) % MAX]);
  }
  printf("\n");
}

int main() {
  front = -1;
  rear = -1;
  enQueue(2);
  Print();
  enQueue(4);
  Print();
  enQueue(6);
  Print();
  deQueue();
  Print();
  enQueue(10);
  Print();
  return 0;
}
