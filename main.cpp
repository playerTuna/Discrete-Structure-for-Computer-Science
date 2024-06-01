#include "bellman.h"
#include "tsp.h"

int main()
{
    // ifstream fin;
    // int G[20][20];
    // int G2[20][20];
    // int BFValue[20];
    // int BFPrev[20];
    // fin.open("C:\\Users\\Nem\\VNU-HCMUT\\Discrete Structure for Computer Science - CO1007\\inMat1.txt");
    // int n = 8;
    // for (int i = 0; i < n; i++)
    // {
    //     BFValue[i] = -1;
    //     BFPrev[i] = -1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         fin >> G[i][j];
    //     }
    // }
    // fin.close();
    // fin.open("C:\\Users\\Nem\\VNU-HCMUT\\Discrete Structure for Computer Science - CO1007\\inMat2.txt");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         fin >> G2[i][j];
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (i % 2)
    //         BF(G, n, 'D', BFValue, BFPrev);
    //     else
    //         BF(G2, n, 'D', BFValue, BFPrev);
    //     cout << "step" << i << ":" << endl;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << BFValue[j] << " ";
    //     }
    //     cout << endl;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << BFPrev[j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << BF_Path(G, n, 'A', 'E') << endl;
    // fin.close();
    ifstream file("621.txt");
    int Graph[20][20];
    if (!file.is_open())
    {
        cout << "Can't open file" << endl;
        return 0;
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            file >> Graph[i][j];
    string output = Traveling(Graph, 12, 'A');
    cout << output << endl;
}
