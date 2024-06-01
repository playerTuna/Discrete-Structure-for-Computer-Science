#include <iostream>
#include <limits>
#include <climits>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

#ifndef BELLMAN_H
#define BELLMAN_H

/*************************************************************
 * Sử dụng thuật toán Bellman-Ford để tìm đường đi ngắn nhất
 * Đầu vào:
 *    graph: Ma trận kề của đồ thị
 *   num_vertices: Số lượng đỉnh của đồ thị
 *   start_vertex: Đỉnh bắt đầu
 *  value_array: Mảng lưu trữ giá trị của đỉnh
 *  prev_array: Mảng lưu trữ đỉnh trước của mỗi đỉnh
 * ***********************************************************/

struct Edge
{
    int u, v, weight;
};
void BF(int Graph[][20], int num_vertices, char start_vertex, int value_array[], int prev_array[]);
string BF_Path(int Graph[][20], int num_vertices, char start_vertex, char goal_vertex);

#endif // BELLMAN_H