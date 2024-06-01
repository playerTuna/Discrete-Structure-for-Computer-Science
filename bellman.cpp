#include "bellman.h"

void BF(int G[20][20], int num_vertex, char start, int value[], int prev[])
{
    int arr[20];
    int start_index = start - 'A';
    if (value[start_index] == -1)
        for (int i = 0; i < num_vertex; ++i)
        {
            value[i] = INT_MAX;
            prev[i] = -1;
            arr[i] = INT_MAX;
        }
    value[start_index] = 0;
    arr[start_index] = 0;
    for (int i = 0; i < num_vertex; ++i)
        arr[i] = value[i];
    for (int i = 0; i < num_vertex; ++i)
    {
        for (int j = 0; j < num_vertex; ++j)
            if (arr[j] != INT_MAX && arr[j] + G[j][i] < value[i])
            {
                value[i] = arr[j] + G[j][i];
                prev[i] = j;
            }
    }
}

string BF_Path(int Graph[][20], int num_vertices, char start_vertex, char goal_vertex)
{
    vector<int> value(num_vertices, INT_MAX);
    vector<int> prev(num_vertices, -1);
    value[start_vertex - 'A'] = 0;

    for (int i = 1; i <= num_vertices - 1; i++)
        for (int u = 0; u < num_vertices; u++)
            for (int v = 0; v < num_vertices; v++)
                if (Graph[u][v] != 0 && value[u] != INT_MAX && value[u] + Graph[u][v] < value[v])
                {
                    value[v] = value[u] + Graph[u][v];
                    prev[v] = u;
                }
    vector<char> path;
    int v = goal_vertex - 'A';
    for (; v != -1; v = prev[v])
        path.push_back((char)(v + 'A'));
    reverse(path.begin(), path.end());
    stringstream ss;
    for (auto i = 0; i < path.size(); i++)
    {
        if (i != path.size() - 1)
            ss << path[i] << " ";
        else
            ss << path[i];
    }
    return ss.str();
}