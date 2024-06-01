#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
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
void TSP(int i);
string Traveling(int Graph [][20], int num_vertex, char start);


#endif // TSP_H