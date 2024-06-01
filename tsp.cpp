#include "tsp.h"

vector<int> bestPath;

void TSP(int i, int num_vertex, vector<int>& X, vector<int>& visited, vector<vector<int>>& cost, int& dist, int& result)
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
                    bestPath = X;
                }
                else
                {
                    dist = temp_dist;
                    TSP(i + 1, num_vertex, X, visited, cost, dist, result);
                    // dist -= cost[X[i - 1]][X[i]];
                }
            }
            // Backtrack:
            visited[j] = 0;
        }
}

string Traveling(int Graph[][20], int num_vertex, char start)
{
    vector<vector<int>> cost(num_vertex+1, vector<int>(num_vertex+1));
    for (int i = 0; i < num_vertex; i++)
        for (int j = 0; j < num_vertex; j++)
            cost[i + 1][j + 1] = Graph[i][j];
    for (int i = 1; i <= num_vertex; i++)
    {
        for (int j = 1; j <= num_vertex; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
    int start_vertex = start - 'A' + 1;
    vector<int> visited(num_vertex+1, 0); // Reset visited array
    vector<int> X(num_vertex+1, 0);       // Reset X array
    int dist = 0;
    int result = INT_MAX;
    visited[start_vertex] = 1;
    X[1] = start_vertex;
    TSP(2, num_vertex, X, visited, cost, dist, result);
    string res = "";
    for (int i = 1; i <= num_vertex; i++)
    {
        res += char(bestPath[i] + 'A' - 1);
        res += " ";
    }
    res += char(bestPath[1] + 'A' - 1);
    res += " ";
    res += to_string(result);
    cout << res;
    return res;
}
