#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    first dot the BFS
*/

class Solution
{
public:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        // In Bfs we know that when we visit first we mark it
        // We stor pair of queue ,in which first item is node it self and src it self
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }

                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // make a visited vector graph
        // Then make the queue
        // make the array of visited to be zero or false
        // then we go with  for loop
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
