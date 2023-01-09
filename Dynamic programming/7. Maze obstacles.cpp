#include <bits/stdc++.h>

using namespace std;

/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value -1 if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0
0 -1 0
0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.

*/

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int paths[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                paths[i][j] = 0;
            else if (i == 0 && j == 0)
                paths[i][j] = 1;

            else
            {
                int up = (i > 0) ? paths[i - 1][j] : 0;
                int left = (j > 0) ? paths[i][j - 1] : 0;
                paths[i][j] = up + left;
            }
        }
    return paths[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> v1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << "\nMaximum paths:" << uniquePathsWithObstacles(v1);

    return 0;
}
