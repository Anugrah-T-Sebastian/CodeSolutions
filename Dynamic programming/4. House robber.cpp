#include <bits/stdc++.h>

using namespace std;

/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

int maxNonAdjacentSum(vector<int> &nums, int start, int end, int k)
{
    // k is used as a index-setter so that maxSum does not go out of bound
    int n = end - start + 1;
    vector<int> maxSum(n, 0);
    for (int i = start; i <= end; i++)
    {
        if (i == start)
            maxSum[i - k] = nums[start];
        else if (i == start + 1)
            maxSum[i - k] = max(nums[start + 1], nums[start]);
        else
        {
            int picked = nums[i] + maxSum[i - 2 - k];
            int notPicked = maxSum[i - 1 - k];
            maxSum[i - k] = max(picked, notPicked);
        }
    }
    return maxSum[n - 1];
}
int rob(vector<int> &nums)
{
    // Similar to sum of non-adjacent element in an array. But take 2 cases where only consider start element or ending element at a time
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    int maxSum1 = maxNonAdjacentSum(nums, 0, n - 2, 0);
    int maxSum2 = maxNonAdjacentSum(nums, 1, n - 1, 1);
    return max(maxSum1, maxSum2);
}

int main()
{
    vector<int> v1 = {5, 6, 6};
    vector<int> v2 = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    vector<int> v3 = {2, 1, 4, 9};
    cout << "\nMaximum sum of non-adjacent elements:" << rob(v1);
    cout << "\nMaximum sum of non-adjacent elements:" << rob(v2);
    cout << "\nMaximum sum of non-adjacent elements:" << rob(v3);

    return 0;
}