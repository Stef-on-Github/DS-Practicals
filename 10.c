/*10. Write a program for selection sort.*/

#include<stdio.h>
#include<stdlib.h>

void selection_sort(int a[], int n);
void display(int a[], int n);

int main()
{
    int i, ch;
    int a[10], n;
    
    printf("Enter How many elements you want to insert: ");
    scanf("%d", &n);
    
    printf("Enter the Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while (1)
    {
        printf("\n1. Sort Array");
        printf("\n2. Display Array");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                selection_sort(a, n);
                printf("\nArray is Sorted\n");
                break;
            case 2:
                display(a, n);
                break;
            case 3:
                exit(0);
            default:
                printf("Enter Proper Choice\n");
        }
    }

    return 0;
}

void selection_sort(int a[], int n)
{
    int i, j, small, temp;
    for (i = 0; i < (n - 1); i++)
    {
        small = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[small])
            {
                small = j;
            }
        }
        temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
}

void display(int a[], int n)
{
    printf("Elements are as follows: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
