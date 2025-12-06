#include <stdio.h>
#include <stdlib.h>

#define MAX 5     // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear  = -1;

// Function to insert an element (Enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d enqueued into the queue\n", value);
    }
}

// Function to delete an element (Dequeue)
int dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Nothing to dequeue\n");
        return -1;
    } else {
        int temp = queue[front];
        front++;
        printf("%d dequeued from the queue\n", temp);
        return temp;
    }
}

// Function to view the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nCurrent Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}