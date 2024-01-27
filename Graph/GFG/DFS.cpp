#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        // any element first mark it visited
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis, ls);
        }
    };
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // When it come to depth , algorithm that goes to dept first, is Depth
        int vis[V] = {0};

        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
