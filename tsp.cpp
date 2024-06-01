#include "tsp.h"

#include <climits>
#include <cstring>
int num_vertex;
int cost[21][21];
int X[21];
int visited[21];
int dist = 0;
int result = INT_MAX;

void TSP(int i)
{
    for (int j = 1; j <= num_vertex; j++)
        if (!visited[j]) // if vertex j is not visited yet
        {
            visited[j] = 1;
            X[i] = j;
            int temp_dist = dist + cost[X[i - 1]][X[i]];
            if (temp_dist < result)
            {
                if (i == num_vertex)
                {
                    // Update result:
                    result = min(result, temp_dist + cost[X[num_vertex]][X[1]]);
                }
                else
                {
                    dist = temp_dist;
                    TSP(i + 1);
                    dist -= cost[X[i - 1]][X[i]];
                }
            }
            // Backtrack:
            visited[j] = 0;
        }
}
string Traveling(int Graph[][20], int num_vertex, char start)
{
    ::num_vertex = num_vertex;
    for (int i = 0; i < num_vertex; i++)
        for (int j = 0; j < num_vertex; j++)
            cost[i + 1][j + 1] = Graph[i][j];
    int start_vertex = start - 'A' + 1;
    memset(visited, 0, sizeof(visited)); // Reset visited array
    memset(X, 0, sizeof(X));             // Reset X array
    dist = 0;
    result = INT_MAX;
    visited[start_vertex] = 1;
    X[1] = start_vertex;
    TSP(2);
    string res = "";
    for (int i = 1; i <= num_vertex; i++)
        res += char(X[i] + 'A' - 1);
    res += char(X[1] + 'A' - 1);
    res += " ";
    res += to_string(result);
    return res;
}