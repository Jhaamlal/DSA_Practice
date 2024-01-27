#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    /*
    => Here we are creating the matrix that is of node weight and circle are the same in this case
    => This is undirected graph .
    => 1 base Indexing graph
    */
    int n, m;
    cin >> n >> m;
    int add[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add[u][v] = 1;
        add[v][u] = 1;
    }

    /*
        Second type of graph ,which we more commonly used .
        [
            1:{1,2,3},
            2:{1,3},
            3:{2,1};
        ]
        In this way we will save the Graph
    */
    vector<int> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj.push_back(v);
        // For directed graph we will remove the , below code
        // Because there is only way to get from ,1 to 2 element
        adj.push_back(u);
    }
    // Ham ramm ji ke ram ji hamare hai ;
    /*
    Weighted graph, in case of matrix we will store the weight , at position
    int vector for we will save them in the form of pair
    */
    return 0;
}
