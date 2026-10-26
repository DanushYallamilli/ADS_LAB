/* Priority queue using 2 arrays - menu driven.
   Lower priority number = higher priority. */
#include <stdio.h>
#define MAX 100

int data[MAX], prio[MAX];
int n = 0;

void enqueue(int value, int priority)
{
    if (n == MAX)
    {
        printf("Queue full\n");
        return;
    }
    data[n] = value;
    prio[n] = priority;
    n++;
}

int dequeue(int *value)
{
    if (n == 0)
    {
        return 0;
    }

    int best = 0;
    for (int i = 1; i < n; i++)
    {
        if (prio[i] < prio[best]) best = i;
    }

    *value = data[best];
    for (int i = best; i < n - 1; i++)
    {
        data[i] = data[i + 1];
        prio[i] = prio[i + 1];
    }
    n--;
    return 1;
}

void display(void)
{
    if (n == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Value\tPriority\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", data[i], prio[i]);
    }
}

int main(void)
{
    int choice, value, priority;
    while (1)
    {
        printf("\n1. Insert\n2. Delete (highest priority)\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority (lower = higher priority): ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                if (dequeue(&value))
                {
                    printf("Deleted: %d\n", value);
                }
                else
                {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
