#include <stdio.h>

#define INITIAL 0
#define VISITED 2

void dfs(int n, int adj[n][n], int start) {
    int stack[100], top = -1;
    int State[n];
    
    for(int i = 0; i < n; i++) {
        State[i] = INITIAL;
    }
    
    stack[++top] = start;
    
    printf("DFS Traversal: ");
    
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
    int n, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    int adj[n][n];
    printf("Enter adjacency matrix (0 or 1):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    dfs(n, adj, start);
    return 0;
}