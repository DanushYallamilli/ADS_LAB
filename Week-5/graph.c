#include <stdio.h>

#define INITIAL 0
#define WAITING 1
#define VISITED 2

void bfs(int n, int adj[n][n], int start) {
    int queue[100], front = 0, rear = 0;
    int State[n];
    
    for(int i = 0; i < n; i++) {
        State[i] = INITIAL;
    }
    
    queue[rear++] = start;
    State[start] = WAITING;
    
    printf("\nBFS Traversal: ");
    
    while(front < rear) {
        int v = queue[front++];
        
        printf("%d ", v);
        State[v] = VISITED;
            
        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && State[i] == INITIAL) {
                queue[rear++] = i;
                State[i] = WAITING;
            }
        }
    }
    printf("\n");
}

void dfs(int n, int adj[n][n], int start) {
    int stack[100], top = -1;
    int State[n];
    
    for(int i = 0; i < n; i++) {
        State[i] = INITIAL;
    }
    
    stack[++top] = start;
    
    printf("\nDFS Traversal: ");
    
    while(top != -1) {
        int v = stack[top--];
        
        if(State[v] == INITIAL) {
            printf("%d ", v);
            State[v] = VISITED;
            
            for(int i = n - 1; i >= 0; i--) {
                if(adj[v][i] == 1 && State[i] == INITIAL) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start, choice;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    int adj[n][n];
    printf("Enter adjacency matrix (0 or 1):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    while(1) {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. Breadth-First Search (BFS)\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                if(start >= 0 && start < n) {
                    bfs(n, adj, start);
                } else {
                    printf("Invalid starting vertex!\n");
                }
                break;
                
            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                if(start >= 0 && start < n) {
                    dfs(n, adj, start);
                } else {
                    printf("Invalid starting vertex!\n");
                }
                break;
                
            case 3:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }
    
    return 0;
}