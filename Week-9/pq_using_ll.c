/* Priority queue using Linked List - menu driven.
   Lower priority number = higher priority. */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node* next;
};

struct Node* head = NULL;

void enqueue(int value, int priority)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || priority < head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(int *value)
{
    if (head == NULL)
    {
        return 0;
    }

    struct Node* temp = head;
    *value = temp->data;

    head = head->next;
    free(temp);
    return 1;
}

void display()
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Value\tPriority\n");
    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
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