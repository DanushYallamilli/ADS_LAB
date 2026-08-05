#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL, *r = NULL, *temp;

void enqueue(int x)
{
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (f == NULL && r == NULL)
    {
        f = r = temp;
    }
    else
    {
        r->next = temp;
        r = temp;
    }
    printf("%d enqueued successfully.\n", x);
}

void dequeue()
{
    if (f == NULL && r == NULL)
    {
        printf("Queue underflow\n");
    }
    else if (f == r)
    {
        printf("Deleted element is %d\n", f->data);
        free(f);
        f = NULL;
        r = NULL;
    }
    else
    {
        temp = f;
        f = f->next;
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    temp = f;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n--- DYNAMIC QUEUE MENU ---\n");
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
                dequeue();
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
