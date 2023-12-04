/*1. Write a program to implement stack using arrays.*/

#include<stdio.h>
#include<conio.h>

void push();
int pop();
void peak();
void traverse();

int stack[5];
int top = -1;

int main()
{
 
 int choice;
 char ch;
 do
 {
  printf("\n1.Push");
  printf("\n2.Pop");
  printf("\n3.Traverse");
  printf("\n4.Peak");
  printf("\n5.Exit");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	push();
	break;
   case 2:
	printf("Deleted element is %d",pop());
	break;
   case 3:
	traverse();
	break;
   case 4:
	peak();
	break;
   case 5:
	choice = 5;
  }
 }while(choice != 5);
 return 0;
}

void push()
{
 int item;
 if (top == 4)
 {
  printf("The stack is full.");
 }
 else
 {
  printf("Enter the element need to be inserted:\n");
  scanf("%d", &item);
  top = top + 1;
  stack[top] = item;
 }
}

int pop()
{
 int item;
 if(top == -1)
 {
  printf("The stack is empty.");
 }
 else
 {
  item = stack[top];
  top = top - 1;
 }
 return(item);
}

void traverse()
{
 int i;
 if(top == -1)
 {
  printf("The stack is empty\n");
 }
 else
 {
  for(i=top; i>=0 ;i--)
  {
   printf("%d\n",stack[i]);
  }
 }
}

void peak()
{
 if(top == -1)
 {
  printf("The stack is empty.\n");
 }
 else
 {
  printf("%d",stack[top]);
 }
}