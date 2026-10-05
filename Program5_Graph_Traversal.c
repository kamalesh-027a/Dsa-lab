#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void BFS(int startVertex) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d", currentVertex);

        for (i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
        if (front < rear) {
            printf(" ");
        }
    }
    printf("\n");
}

void DFSUtil(int vertex) {
    int i;
    printf("%d", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            printf(" ");
            DFSUtil(i);
        }
    }
}

void DFS(int startVertex) {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("DFS Traversal: ");
    DFSUtil(startVertex);
    printf("\n");
}

int main() {
    int edges, i, u, v, startBFS, startDFS;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter the number of edges: ");
    if (scanf("%d", &edges) != 1) return 0;

    for (i = 0; i < edges; i++) {
        printf("Enter edge (origin destination): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter the start vertex for BFS: ");
    scanf("%d", &startBFS);
    BFS(startBFS);

    printf("Enter the start vertex for DFS: ");
    scanf("%d", &startDFS);
    DFS(startDFS);

    return 0;
}

/*
============================================================
OUTPUT
============================================================

Enter the number of vertices: 5
Enter the number of edges: 5
Enter edge (origin destination): 0 1
Enter edge (origin destination): 0 2
Enter edge (origin destination): 1 3
Enter edge (origin destination): 1 4
Enter edge (origin destination): 3 4
Enter the start vertex for BFS: 0
BFS Traversal: 0 1 2 3 4
Enter the start vertex for DFS: 0
DFS Traversal: 0 1 3 4 2

============================================================
RESULT
============================================================

Thus the c program to perform graph traversal techniques using
Depth-First Search (DFS) and Breadth-First Search (BFS) has been
successfully implemented.

============================================================
*/
