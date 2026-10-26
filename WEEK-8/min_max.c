#include <stdio.h>

int val[100], min[100], max[100], top = -1;

int main() {
    int choice, v;
    printf("Commands -> 1: Push, 2: Pop, 3: View Top Min/Max, 4: Display All, 0: Exit\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &v);
            top++;
            val[top] = v;
            min[top] = (top == 0 || v < min[top-1]) ? v : min[top-1];
            max[top] = (top == 0 || v > max[top-1]) ? v : max[top-1];
            printf("Pushed %d\n", v);
        } 
        else if (choice == 2 && top >= 0) {
            printf("Popped %d\n", val[top]);
            top--;
        } 
        else if (choice == 3 && top >= 0) {
            printf("Current Min: %d, Max: %d\n", min[top], max[top]);
        } 
        else if (choice == 4) {
            printf("Stack (Top to Bottom):\n");
            if (top == -1) printf("Empty\n");
            for (int i = top; i >= 0; i--) {
                printf("[%d] Val: %d | Min: %d | Max: %d\n", i, val[i], min[i], max[i]);
            }
        } 
        else if (choice == 0) {
            break;
        } 
        else {
            printf("Invalid command or stack is empty.\n");
        }
    }
    return 0;
}