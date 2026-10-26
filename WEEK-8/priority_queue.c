#include <stdio.h>

#define SIZE 10

int arr[SIZE], priority[SIZE], count = 0;

int main(void) {
    int choice, val, p, i;
    printf("Commands -> 1: Enqueue, 2: Dequeue, 3: Display, 0: Exit\n");
    printf("Higher priority number is served first.\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1 && count < SIZE) {
            scanf("%d %d", &val, &p);
            i = count;
            while (i > 0 && priority[i - 1] < p) {
                arr[i] = arr[i - 1];
                priority[i] = priority[i - 1];
                i--;
            }
            arr[i] = val;
            priority[i] = p;
            count++;
            printf("Enqueued %d with priority %d\n", val, p);
        }
        else if (choice == 2 && count > 0) {
            printf("Dequeued %d with priority %d\n", arr[0], priority[0]);
            for (i = 1; i < count; i++) {
                arr[i - 1] = arr[i];
                priority[i - 1] = priority[i];
            }
            count--;
        }
        else if (choice == 3) {
            printf("Priority Queue: ");
            if (count == 0) {
                printf("Empty");
            }
            for (i = 0; i < count; i++) {
                printf("[%d, priority %d] ", arr[i], priority[i]);
            }
            printf("\n");
        }
        else if (choice == 0) {
            break;
        }
        else {
            printf("Invalid command, queue full, or queue empty.\n");
        }
    }
    return 0;
}
