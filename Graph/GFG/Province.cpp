#include <iostream>
using namespace std;
class Solution
{
public:
    int dfs(int Node, vector<int> adjList[], int vis[])
    {
        vis[Node] = 1;
        for (auto it : adjList[Node])
        {
            if (!vis[it])
            {
                dfs(it, adjList, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        /*
        We are given adjacency matrix, in first option we need to calculate
        the the the Matrix ,int list
        */
        vector<int> adjList[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[i].push_back(i);
                }
            }
        }
        // We need to pass item in the for loop for DFS
        // Because the Graph are disJoint,they are not together
        int vis[V] = {0};
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
