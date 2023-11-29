#include <iostream>
using namespace std;
class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> tempVector = mat;
        while (k != 0)
        {
            for (int i = 0; i < row; i++)
            {
                if (!tempVector[i].empty())
                {
                    int item = tempVector[i].back();                   // Save the last element
                    tempVector[i].pop_back();                          // Remove the last element
                    tempVector[i].insert(tempVector[i].begin(), item); // Insert the saved element at the beginning
                }
            }
            k--;
        }

        if (mat == tempVector)
            return true;
        else
            return false;
    }
};

#include <vector>
#include <iostream>

int main()
{
    // Initialize a 2D vector
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Print the matrix before removing the last element

    return 0;
}
