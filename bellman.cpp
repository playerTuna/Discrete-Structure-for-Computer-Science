#include "bellman.h"
void BF(int G[20][20], int num_vertex, char start, int value[], int prev[])
{
    int start_index = start - 'A';
    if (value[start_index] == -1)
    {
        for (int i = 0; i < num_vertex; ++i)
        {
            value[i] = -1;
            prev[i] = -1;
        }
        value[start_index] = 0;
    }
    int arr[20];
    for (int i = 0; i < num_vertex; ++i)
        arr[i] = value[i];
    for (int i = 0; i < num_vertex; ++i)
    {
        for (int j = 0; j < num_vertex; ++j)
        {
            if (arr[j] != -1 && G[j][i] != 0)
            {
                if (value[i] == -1 || arr[j] + G[j][i] < value[i])
                {
                    value[i] = arr[j] + G[j][i];
                    prev[i] = j;
                }
            }
        }
    }
}

string BF_Path(int Graph[20][20], int num_vertices, char start_vertex, char goal_vertex)
{
    vector<int> value(num_vertices, INT_MAX);
    vector<int> prev(num_vertices, -1);
    value[start_vertex - 'A'] = 0;
    int start_index = start_vertex - 'A';
    if (value[start_index] == -1)
    {
        for (int i = 0; i < num_vertices; ++i)
        {
            value[i] = INT_MAX;
            prev[i] = -1;
        }
        value[start_index] = 0;
    }
    for (int k = 0; k < num_vertices - 1; ++k)
    {
        vector<int> arr = value;
        for (int i = 0; i < num_vertices; ++i)
        {
            for (int j = 0; j < num_vertices; ++j)
            {
                if (arr[j] != INT_MAX && Graph[j][i] != 0 && arr[j] + Graph[j][i] < value[i])
                {
                    value[i] = arr[j] + Graph[j][i];
                    prev[i] = j;
                }
            }
        }
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
