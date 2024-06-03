#include "tsp.h"

vector<int> bestPath;

void TSP(int i, int num_vertex, vector<int> &status, vector<int> &visited, vector<vector<int>> &cost, int &dist, int &result, int min_cost)
{
    for (int j = 1; j <= num_vertex; j++)
        if (!visited[j] && cost[status[i - 1]][j] != INT_MAX)
        {
            visited[j] = 1;
            status[i] = j;
            int temp_dist = dist;
            if (cost[status[i - 1]][status[i]] != INT_MAX)
            {
                temp_dist += cost[status[i - 1]][status[i]];
            }
            if (i == num_vertex)
            {
                if (cost[status[num_vertex]][status[1]] != INT_MAX)
                {
                    temp_dist += cost[status[num_vertex]][status[1]];
                }
                if (temp_dist < result)
                {
                    result = temp_dist;
                    bestPath = vector<int>(status.begin(), status.end());
                }
            }
            else if (temp_dist + (num_vertex - i + 1) * min_cost < result)
            {
                dist = temp_dist;
                TSP(i + 1, num_vertex, status, visited, cost, dist, result, min_cost);
                dist -= cost[status[i - 1]][status[i]];
            }
            visited[j] = 0;
        }
}

string Traveling(int Graph[20][20], int num_vertex, char start)
{
    vector<vector<int>> cost(num_vertex + 1, vector<int>(num_vertex + 1, INT_MAX));
    for (int i = 0; i < num_vertex; i++)
    {
        for (int j = 0; j < num_vertex; j++)
            cout << Graph[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < num_vertex; i++)
        for (int j = 0; j < num_vertex; j++)
            if (Graph[i][j] != 0)
                cost[i + 1][j + 1] = Graph[i][j];
    int start_vertex = start - 'A' + 1;
    vector<int> visited(num_vertex + 1, 0);
    vector<int> X(num_vertex + 1, 0);
    int dist = 0;
    int result = INT_MAX;
    visited[start_vertex] = 1;
    X[1] = start_vertex;
    int min_cost = INT_MAX;
    for (int i = 1; i <= num_vertex; i++)
        for (int j = 1; j <= num_vertex; j++)
            if (i != j && cost[i][j] < min_cost)
                min_cost = cost[i][j];
    TSP(2, num_vertex, X, visited, cost, dist, result, min_cost);
    string res = "";
    if (!bestPath.empty() && bestPath.size() >= num_vertex)
    {
        for (int i = 1; i <= num_vertex; i++)
        {
            res += char(bestPath[i] + 'A' - 1);
            res += " ";
        }
        res += char(bestPath[1] + 'A' - 1);
        res += " ";
        res += to_string(result);
    }
    else
        res = "";
    return res;
}
