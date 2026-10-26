#include <stdio.h>

int stack[100], redo_stack[100], top = -1, r_top = -1;

int main() {
    int choice, val;
    printf("Commands -> 1: Push, 2: Undo, 3: Redo, 4: Display, 0: Exit\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &val);
            stack[++top] = val;  // Push to main stack
            r_top = -1;          // Clear redo history on new push
            printf("Pushed %d.\n", val);
        } 
        else if (choice == 2 && top >= 0) {
            redo_stack[++r_top] = stack[top--]; // Pop main, push to redo
            printf("Undid push.\n");
        } 
        else if (choice == 3 && r_top >= 0) {
            stack[++top] = redo_stack[r_top--]; // Pop redo, push to main
            printf("Redid push.\n");
        } 
        else if (choice == 4) {
            printf("Current Stack: ");
            if (top == -1) printf("Empty");
            for (int i = 0; i <= top; i++) {
                printf("%d ", stack[i]);
            }
            printf("\n");
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