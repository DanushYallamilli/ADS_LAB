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
    
    printf("BFS Traversal: ");
    
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
    
    bfs(n, adj, start);
    return 0;
}