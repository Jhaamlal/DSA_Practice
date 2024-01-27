#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Created a vector to check is that element is visited or not
        // Intitalise with zero to that item
        vector<int> visited(V, 0);
        // put the index of the first item in the vector ,that visited by
        // By making it first node visited =1 .
        // Once that will happen ,put that in the queqe

        visited[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            // take out the element from the quequ

            int node = q.front();
            q.pop();
            // push it into the Node
            bfs.push_back(node);

            // one you take the value ,now
            // iterate over the all the element of the  ,array  join to it
            // if it is not  visted put that into ,quequ
            // if already visited means that ,already is in quequ or passed through it
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
