#include <bits/stdc++.h>

using namespace std;

/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.

*/

int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    int minSumPaths[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                minSumPaths[i][j] = grid[0][0];
            else
            {
                int up = (i > 0) ? (grid[i][j] + minSumPaths[i - 1][j]) : INT_MAX;
                int left = (j > 0) ? (grid[i][j] + minSumPaths[i][j - 1]) : INT_MAX;
                minSumPaths[i][j] = min(up, left);
            }
        }
    }

    return minSumPaths[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> v1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << "\nMaximum paths:" << minSumPath(v1);

    return 0;
}