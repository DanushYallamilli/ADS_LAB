/* Priority queue using Min-Heap - menu driven.
   Lower priority number = higher priority. */
#include <stdio.h>
#define MAX 100

int data[MAX], prio[MAX];
int n = 0;

// Helper function to swap two elements in both parallel arrays
void swap(int i, int j)
{
    int tempData = data[i];
    data[i] = data[j];
    data[j] = tempData;

    int tempPrio = prio[i];
    prio[i] = prio[j];
    prio[j] = tempPrio;
}

// Restores the min-heap property by bubbling a new element up
void heapify_up(int index)
{
    if (index > 0)
    {
        int parent = (index - 1) / 2;
        // If the child's priority number is lower (higher priority), swap them
        if (prio[index] < prio[parent])
        {
            swap(index, parent);
            heapify_up(parent);
        }
    }
}

// Restores the min-heap property by sinking the root element down
void heapify_down(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && prio[left] < prio[smallest])
    {
        smallest = left;
    }
    if (right < n && prio[right] < prio[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(index, smallest);
        heapify_down(smallest);
    }
}

void enqueue(int value, int priority)
{
    if (n == MAX)
    {
        printf("Queue full\n");
        return;
    }
    // Insert at the end of the arrays
    data[n] = value;
    prio[n] = priority;
    
    // Bubble up to maintain min-heap property
    heapify_up(n);
    n++;
}

int dequeue(int *value)
{
    if (n == 0)
    {
        return 0;
    }

    // The highest priority element is always at the root (index 0)
    *value = data[0];
    
    // Move the last element in the heap to the root
    data[0] = data[n - 1];
    prio[0] = prio[n - 1];
    n--;
    
    // Sink the new root down to maintain min-heap property
    heapify_down(0);
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
    // Prints the array exactly as it is stored (Level-Order traversal)
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