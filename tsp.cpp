#include "tsp.h"

vector<int> bestPath;

void TSP(int i, int num_vertex, vector<int> &X, vector<int> &visited, vector<vector<int>> &cost, int &dist, int &result, int min_cost, int start_vertex)
{
    for (int j = 1; j <= num_vertex; j++)
        if (!visited[j] && cost[X[i - 1]][j] != INT_MAX) // If not visited and can move to vertex j
        {
            visited[j] = 1; // Mark as visited
            X[i] = j;       // Store vertex j
            int temp_dist = dist;
            if (cost[X[i - 1]][X[i]] != INT_MAX)
            {
                temp_dist += cost[X[i - 1]][X[i]]; // Update distance
            }
            if (i == num_vertex) // If all vertices are visited
            {
                if (cost[X[num_vertex]][start_vertex] != INT_MAX)
                {
                    temp_dist += cost[X[num_vertex]][start_vertex]; // Update distance
                    if (temp_dist < result)
                    {
                        result = temp_dist;                         // Update shortest distance
                        bestPath = vector<int>(X.begin(), X.end()); // Store the shortest path
                    }
                }
            }
            else if (temp_dist + (num_vertex - i + 1) * min_cost < result) // If current distance is less than the shortest distance
            {
                dist = temp_dist;
                TSP(i + 1, num_vertex, X, visited, cost, dist, result, min_cost, start_vertex); // Recursive, continue searching
                dist -= cost[X[i - 1]][X[i]];                                                   // Backtrack
            }
            visited[j] = 0; // Unmark
        }
}

string Traveling(int Graph[20][20], int num_vertex, char start)
{
    vector<vector<int>> cost(num_vertex + 1, vector<int>(num_vertex + 1, INT_MAX));
    for (int i = 0; i < num_vertex; i++)
        for (int j = 0; j < num_vertex; j++)
            if (Graph[i][j] != 0)
                cost[i + 1][j + 1] = Graph[i][j]; // Store adjacency matrix
    int start_vertex = start - 'A' + 1;
    if (Graph[num_vertex - 1][start_vertex - 1] == 0) // If unable to return to the start vertex
        cost[num_vertex][start_vertex] = INT_MAX;     // Assign INT_MAX
    vector<int> visited(num_vertex + 1, 0);
    vector<int> X(num_vertex + 1, 0);
    int dist = 0;
    int result = INT_MAX;
    visited[start_vertex] = 1;
    X[1] = start_vertex;
    int min_cost = INT_MAX;
    for (int i = 1; i <= num_vertex; i++) // Traverse all vertices
        for (int j = 1; j <= num_vertex; j++)
            if (i != j && cost[i][j] < min_cost) // Find the minimum value
                min_cost = cost[i][j];
    TSP(2, num_vertex, X, visited, cost, dist, result, min_cost, start_vertex); // Find the next vertex
    string res = "";
    if (!bestPath.empty() && bestPath.size() >= num_vertex)
    {
        if (cost[bestPath[num_vertex]][start_vertex] == INT_MAX)
        {
            cost[bestPath[num_vertex]][start_vertex] = 0;
            bestPath.push_back(start_vertex);
        }
        for (int i = 1; i <= num_vertex; i++)
        {
            res += char(bestPath[i] + 'A' - 1);
            res += " ";
        }
        res += char(bestPath[1] + 'A' - 1);
        res += " ";
        res += to_string(result);
    }
    return res;
}
