#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

#ifndef TSP_H
#define TSP_H

/************************************************************
 * Sử dụng chu trình Hamilton để giải vấn đề TSP
 * Đầu vào:
 *     graph: Ma trận kề của đồ thị
 *   num_vertex: Số lượng đỉnh của đồ thị
 *    start: Đỉnh bắt đầu
 * Đầu ra:
 *    In ra đường đi ngắn nhất và độ dài của nó
 *************************************************************/
void TSP(int i, int num_vertex, vector<int> &X, vector<int> &visited, vector<vector<int>> &cost, int &dist, int &result, int min_cost, int start_vertex);
string Traveling(int Graph[20][20], int num_vertex, char start);

#endif // TSP_H
