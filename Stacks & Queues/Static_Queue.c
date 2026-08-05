#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue
{
    int a[MAX];
    int r, f;
} q;

void enqueue(int x)
{
    if (q.r == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        q.r++;
        q.a[q.r] = x;
        printf("%d enqueued successfully.\n", x);
    }
}

int dequeue()
{
    if (q.r < q.f)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return q.a[q.f++];
    }
}

void display()
{
    if (q.r < q.f)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q.f; i <= q.r; i++)
    {
        printf("%d ", q.a[i]);
    }
    printf("\n");
}

int main()
{
    q.f = 0;
    q.r = -1; // Initialization
    int choice, val, res;

    while (1)
    {
        printf("\n--- STATIC QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                res = dequeue();
                if (res != -1)
                {
                    printf("Dequeued element: %d\n", res);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
