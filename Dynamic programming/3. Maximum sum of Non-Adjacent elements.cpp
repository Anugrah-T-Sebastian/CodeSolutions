#include <bits/stdc++.h>

using namespace std;

/*
You are given an array/list of ‘N’ integers.
You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Example:
9
1 2 3 1 3 5 8 1 9
maximum sum: 24

Solution: (By me)
maxSum[till 0] = nums[0]
maxSum[till 1] = nums[1]
maxSum[till 2] = max(nums[2] + maxSum[till 0], nums[2] + maxSum[till 1] - nums[1 : Since it is adjacent to 2])      with the second condition we also include non-adjacent element till 2
maxSum[till 2] = max(nums[3] + maxSum[till 1], nums[3] + maxSum[till 2] - nums[2 : Since it is adjacent to 3])      with the second condition we also include non-adjacent element till 3
maxSum[i] = max(nums[i] + maxSum[i - 2], nums[i] + maxSum[i - 1] - nums[i - 1]);
Maximum sum of non-adjacent elements: max(maxSum[n - 2], maxSum[n - 1])
*/

int maxSumOfNonAdjacentElements_1(vector<int> nums)
{
    vector<int> maxSum(nums.size(), 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            maxSum[i] = nums[0];
        else if (i == 1)
            maxSum[i] = nums[1];
        else
            maxSum[i] = max(nums[i] + maxSum[i - 2], nums[i] + maxSum[i - 1] - nums[i - 1]);
    }
    return max(maxSum[n - 2], maxSum[n - 1]);
}

int maxSumOfNonAdjacentElements_2(vector<int> nums)
{
    vector<int> maxSum(nums.size(), 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            maxSum[i] = nums[0];
        else if (i == 1)
            maxSum[i] = max(nums[1], nums[0]);
        else
        {
            int picked = nums[i] + maxSum[i - 2];
            int not_picked = maxSum[i - 1];
            maxSum[i] = max(picked, not_picked);
        }
    }
    return maxSum[n - 1];
}

int main()
{
    vector<int> v1 = {5, 6, 6};
    vector<int> v2 = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    vector<int> v3 = {2, 1, 4, 9};
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_1(v1);
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_1(v2);
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_1(v3);
    cout << "\n************************************************************";
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_2(v1);
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_2(v2);
    cout << "\nMaximum sum of non-adjacent elements:" << maxSumOfNonAdjacentElements_2(v3);
    return 0;
}