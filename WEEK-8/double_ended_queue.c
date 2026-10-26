#include <stdio.h>

#define n 10

int arr[n], front = -1, rear = -1;

int main() 
{
    int choice, val;
    printf("MENU\n1: Insert Front, 2: Insert Rear, 3: Delete Front, 4: Delete Rear, 5: Display, 0: Exit\n");

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
                front = (front - 1 + n) % n;
            }
            arr[front] = val;
            printf("Inserted %d at front\n", val);
        }
        else if (choice == 2 && (front == -1 || (rear + 1) % n != front)) 
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
            printf("Inserted %d at rear\n", val);
        }
        else if (choice == 3 && front != -1) 
        {
            printf("Deleted %d from front\n", arr[front]);
            if (front == rear) 
            {
                front = rear = -1;
            } else 
            {
                front = (front + 1) % n;
            }
        }
        else if (choice == 4 && front != -1) 
        {
            printf("Deleted %d from rear\n", arr[rear]);
            if (front == rear) 
            {
                front = rear = -1;
            } else 
            {
                rear = (rear - 1 + n) % n;
            }
        }
        else if (choice == 5) 
        {
            printf("Display: ");
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
