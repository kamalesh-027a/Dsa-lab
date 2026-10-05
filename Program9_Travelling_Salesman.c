#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 15
#define INF 999999

int n;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int next = 0; next < n; next++) {
        if (!(mask & (1 << next))) {
            int newCost = cost[pos][next] + tsp(mask | (1 << next), next);
            if (newCost < ans) {
                ans = newCost;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int i, j;

    printf("Enter the number of cities: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    int minCost = tsp(1, 0);

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}

/*
============================================================
OUTPUT
============================================================

Enter the number of cities: 4
Enter the cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Minimum cost of the TSP: 80

============================================================
RESULT
============================================================

Thus the C program to implement and demonstrate the Travelling
Salesman Problem (TSP) using dynamic programming has been
executed successfully.

============================================================
*/
