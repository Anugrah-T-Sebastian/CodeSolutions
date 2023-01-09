#include <bits/stdc++.h>

using namespace std;

/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves).
Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/

int ninjTrainig(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> credits(n, vector<int>(3, 0));
    int maxCredit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                credits[i][j] = points[i][j];
                if (credits[i][j] > maxCredit)
                    maxCredit = max(credits[i][j], maxCredit);
            }
            else
            {
                int picked = points[i][j] + max(credits[i - 1][(j + 1) % 3], credits[i - 1][(j + 2) % 3]);
                int notPicked = credits[i - 1][j];
                credits[i][j] = max(picked, notPicked);
                if (credits[i][j] > maxCredit)
                    maxCredit = max(credits[i][j], maxCredit);
            }
        }
    }
    return maxCredit;
}

int main()
{
    vector<vector<int>> v1 = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    vector<vector<int>> v2 = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    cout << "\nMaximum credits:" << ninjTrainig(v1);
    cout << "\nMaximum credits:" << ninjTrainig(v2);

    return 0;
}