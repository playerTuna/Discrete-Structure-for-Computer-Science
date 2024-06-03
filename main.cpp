// #include "bellman.h"
#include "tsp.h"

// int main() {
//     int G[20][20];
//     int n = 12;
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 100);
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             G[i][j] = dis(gen);
//             std::cout << G[i][j] << " ";
//         }
//     }
//     string output = Traveling(G, n, 'A');
//     std::cout << "Output: " << output << std::endl;
//     return 0;
// }
// int main()
// {
//     ifstream fin;
//     int G[20][20];
//     int G2[20][20];
//     int BFValue[20];
//     int BFPrev[20];
//     fin.open("inMat1.txt");
//     int n = 8;
//     for (int i = 0; i < n; i++)
//     {
//         BFValue[i] = -1;
//         BFPrev[i] = -1;
//         for (int j = 0; j < n; j++)
//         {
//             fin >> G[i][j];
//         }
//     }

//     fin.open("inMat2.txt");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             fin >> G2[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (i % 2)
//             BF(G, n, 'D', BFValue, BFPrev);
//         else
//             BF(G2, n, 'D', BFValue, BFPrev);
//         cout << "step" << i << ":" << endl;
//         for (int j = 0; j < n; j++)
//         {
//             cout << BFValue[j] << " ";
//         }
//         cout << endl;
//         for (int j = 0; j < n; j++)
//         {
//             cout << BFPrev[j] << " ";
//         }
//         cout << endl;
//     }
//     fin.close();
// }

int main()
{
    int G[20][20];
    ifstream fin;
    fin.open("C:\\Users\\Nem\\VNU-HCMUT\\Discrete Structure for Computer Science - CO1007\\354.txt");
    int n = 12;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> G[i][j];
        }
    }
    string output = Traveling(G, n, 'A');
    cout << output << endl;
    fin.close();
}
