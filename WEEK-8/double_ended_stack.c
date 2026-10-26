#include <stdio.h>

int arr[10], top1 = -1, top2 = 10;

int main() {
    int choice, val;
    printf("Commands -> 1: Push1, 2: Push2, 3: Pop1, 4: Pop2, 5: Display, 0: Exit\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1 && top1 + 1 < top2) {
            scanf("%d", &val);
            arr[++top1] = val;
            printf("Pushed %d to Stack 1\n", val);
        } 
        else if (choice == 2 && top1 + 1 < top2) {
            scanf("%d", &val);
            arr[--top2] = val;
            printf("Pushed %d to Stack 2\n", val);
        } 
        else if (choice == 3 && top1 >= 0) {
            printf("Popped %d from Stack 1\n", arr[top1--]);
        } 
        else if (choice == 4 && top2 < 10) {
            printf("Popped %d from Stack 2\n", arr[top2++]);
        } 
        else if (choice == 5) {
            printf("Stack 1: ");
            if (top1 == -1) printf("Empty");
            for (int i = 0; i <= top1; i++) printf("%d ", arr[i]);
            
            printf("\nStack 2: ");
            if (top2 == 10) printf("Empty");
            for (int i = 9; i >= top2; i--) printf("%d ", arr[i]);
            printf("\n");
        } 
        else if (choice == 0) {
            break;
        } 
        else {
            printf("Invalid command, stack full, or stack empty.\n");
        }
    }
    return 0;
}
