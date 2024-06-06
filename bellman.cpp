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
    vector<int> prevStep(num_vertex);
    for (int i = 0; i < num_vertex; ++i)
        prevStep[i] = value[i];
    for (int i = 0; i < num_vertex; ++i)
    {
        for (int j = 0; j < num_vertex; ++j)
        {
            if (prevStep[i] != -1 && G[i][j] != 0)
            {
                if (value[j] == -1 || prevStep[i] + G[i][j] < value[j])
                {
                    value[j] = prevStep[i] + G[i][j];
                    prev[j] = i;
                }
            }
        }
    }
}

string BF_Path(int Graph[20][20], int num_vertex, char start_vertex, char goal_vertex)
{
    vector<int> value(num_vertex, INT_MAX);
    vector<int> prev(num_vertex, -1);
    value[start_vertex - 'A'] = 0;
    int start_index = start_vertex - 'A';
    if (value[start_index] == -1)
    {
        for (int i = 0; i < num_vertex; ++i)
        {
            value[i] = INT_MAX;
            prev[i] = -1;
        }
        value[start_index] = 0;
    }
    for (int k = 0; k < num_vertex - 1; ++k)
    {
        vector<int> prevStep = value;
        for (int i = 0; i < num_vertex; ++i)
        {
            for (int j = 0; j < num_vertex; ++j)
            {
                if (prevStep[i] != INT_MAX && Graph[i][j] != 0 && prevStep[i] + Graph[i][j] < value[j])
                {
                    value[j] = prevStep[i] + Graph[i][j];
                    prev[j] = i;
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
