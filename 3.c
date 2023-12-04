/*3. Write a program to implement a stack using a linked list.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void push();
void pop();
void display();

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    int choice = 0;
    printf("\nStack Operations Using Linked List\n");
    while (choice != 4)
    {
	printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	    push();
	    break;
	case 2:
	    pop();
	    break;
	case 3:
	    display();
	    break;
	case 4:
	    printf("\nBye Bye....Exiting\n");
	    return 0;
	default:
	    printf("\nEnter a valid choice\n");
	    break;
	}
    }
    return 0;
}

void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
	printf("Not Able to Push the Element\n");
    }
    else
    {
	printf("Enter the value: ");
	scanf("%d", &val);
	ptr->val = val;
	ptr->next = head;
	head = ptr;
	printf("Value Pushed\n");
    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
	printf("Underflow\n");
    }
    else
    {
	item = head->val;
	ptr = head;
	head = head->next;
	free(ptr);
	printf("Item Popped: %d\n", item);
    }
}

void display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
	printf("\nStack is Empty\n");
    }
    else
    {
	printf("Printing Stack Elements\n");
	while (ptr != NULL)
	{
	    printf("%d\n", ptr->val);
	    ptr = ptr->next;
	}
    }
}