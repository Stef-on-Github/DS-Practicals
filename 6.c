/*6. Write a program to implement a circular queue using arrays.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int x);
int dequeue();
void display();

int main()
{
    int choice;
    int var;

    while (1)
    {
        printf("Enter your choice :\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &var);
            enqueue(var);
            break;
        case 2:
            var = dequeue();
            if (var != -1)
                printf("The dequeued element is %d\n", var);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int var)
{
    if ((front == 0 && rear == SIZE - 1) || (rear == front - 1))
    {
        printf("Queue is full\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = var;
    }
    else if (rear == SIZE - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = var;
    }
    else
    {
        rear++;
        queue[rear] = var;
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;

        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("%d ", queue[i]);
                i++;
            }
        }
        else
        {
            while (i < SIZE)
            {
                printf("%d ", queue[i]);
                i++;
            }

            i = 0;
            while (i <= rear)
            {
                printf("%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}
