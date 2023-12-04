/*2. Write a program to implement a queue using arrays.*/

#include<stdio.h>
#include<conio.h>
#define SIZE 100
void enqueue();
void dequeue();
void show();
int queue[SIZE];
int rear=-1;
int front=-1;
int main()
{
	int ch;
	bool value = true;
	while(value)
	{
		printf("1.Enqueue operation\n");
		printf("2.Dequeue operation\n");
		printf("3.Display the queue\n");
		printf("4.Exit\n");
		printf("Enter your choice of operation\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				show();
				break;
			case 4:
				value = false;
			default:
				printf("\nChoice is Invalid...!!!\n");
		}
	}
	return 0;
}
void enqueue()
{
	int value;
	if(rear==SIZE-1)
	{
		printf("\nOverflow...!!!\n");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("\nEnter element to be added\n");
		scanf("%d",&value);
		rear=rear+1;
		queue[rear]=value;
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("\nUnderflow...!!!\n");
		return;
	}
	else
	{
		printf("\nElement deleted from queue %d\n",queue[front]);
		front=front+1;
	       //	rear=rear-1;
		return;
	}
}
void show()
{
	int i;
	if(front==-1 || front>rear)
	{
		printf("\nQueue is empty...!!!\n");
	}
	else
	{
		for(i=front;i<rear+1;i++)
		{
			printf(" %d",queue[i]);
		}
		printf("\n");
	}
}