#include <stdio.h>

#define n 10

int arr[n], front = -1, rear = -1;

int main() 
{
    int choice, val;
    printf("MENU\n1: Enqueue, 2: Dequeue, 3: Display, 0: Exit\n");

    while (1) 
    {
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1 && (front == -1 || (rear + 1) % n != front)) 
        {
            scanf("%d", &val);
            if (front == -1) 
            {
                front = rear = 0;
            } else 
            {
                rear = (rear + 1) % n;
            }
            arr[rear] = val;
            printf("Enqueued %d\n", val);
        }
        else if (choice == 2 && front != -1) 
        {
            printf("Dequeued %d\n", arr[front]);
            if (front == rear)
            {
                front = rear = -1;
            } else 
            {
                front = (front + 1) % n;
            }
        }
        else if (choice == 3) 
        {
            printf("Queue: ");
            if (front == -1) 
            {
                printf("Empty");
            } else 
            {
                int i = front;
                while (1) 
                {
                    printf("%d ", arr[i]);
                    if (i == rear) break;
                    i = (i + 1) % n;
                }
            }
            printf("\n");
        }
        else if (choice == 0) 
        {
            break;
        }
        else 
        {
            printf("Invalid (or) queue full (or) queue empty.\n");
        }
    }
    return 0;
}
