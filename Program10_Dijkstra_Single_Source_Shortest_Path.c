#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index = -1;
    int v;

    for (v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int n) {
    int i;
    printf("Vertex Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];
    int i, count, v;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;

        sptSet[u] = 1;

        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph, 0);

    return 0;
}

/*
============================================================
OUTPUT
============================================================

Vertex Distance from Source
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14

============================================================
RESULT
============================================================

Thus the C program to find shortest path has been implemented
successfully.

============================================================
*/
