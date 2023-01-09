#include <bits/stdc++.h>

using namespace std;

/*
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair.
HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair.
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20.

Sol: (By me)
minEnergy[till 1] = H[1] - H[0]
minEnergy[till 2] = min(H[2] - H[0], (H[2] - H[1]) + (H[1] - H[0])) => min(H[2] - H[0], (H[2] - H[1]) + minEnergy[till 1])
minEnergy[till 3] = min(H[3] - H[2] + minEnergy[till 2], H[3] - H[1] + minEngry[till 1])
minEnergy[till i] = min(H[i] - H[i-2] + minEnergy[till i-2], H[i] - H[i-1] + minEngry[till i-1])
*/

int minEnergyRequired(vector<int> heights, int n)
{
    vector<int> minEnergy(heights.size(), 0);

    for (int i = 1; i < n; i++)
    {
        if (i == 1)
            minEnergy[i] = heights[i] - heights[i - 1];
        else if (i == 2)
            minEnergy[i] = min(heights[i] - heights[i - 2], heights[i] - heights[i - 1] + minEnergy[i - 1]);

        else
            minEnergy[i] = min(heights[i] - heights[i - 2] + minEnergy[i - 2], heights[i - 1] + heights[i - 1] + minEnergy[i - 1]);
    }
    return minEnergy[n - 1];
}

int main()
{
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum energy:" << minEnergyRequired(v, 3);
    return 0;
}