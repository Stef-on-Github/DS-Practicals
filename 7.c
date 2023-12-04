/*7. Write a program to implement double ended queue (dequeue) using arrays.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    queue[front] = item;
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
}

void deleteFront() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

int getFront() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue[front];
}

int getRear() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue[rear];
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, item;

    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Get Front\n");
    printf("6. Get Rear\n");
    printf("7. Display Queue\n");
    printf("8. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                printf("Front element: %d\n", getFront());
                break;
            case 6:
                printf("Rear element: %d\n", getRear());
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
