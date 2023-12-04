/*4. Write a program to implement a queue using a linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Queue 
{
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) 
    {
        perror("Memory allocation failed");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) 
{
    struct Node* newNode = createNode(data);
    if (!queue->rear) 
    {
        queue->front = queue->rear = newNode;
    } else 
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (!queue->front) 
    {
        printf("Queue is empty.\n");
        exit(1);
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void displayQueue(struct Queue* queue) 
{
    struct Node* current = queue->front;
    if (!current) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (current) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() 
{
    struct Queue* queue = createQueue();
    int choice, element;

    while (1) 
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                if (!queue->front)
                    printf("Queue is empty.\n");
                else
                    printf("Dequeued element: %d\n", dequeue(queue));
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
