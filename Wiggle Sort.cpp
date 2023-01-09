#include<bits/stdc++.h>

using namespace std;

vector<int> wiggleSortAll(vector<int> nums)    //TC = O(n*logn)    SC = O(n)
{
    //Reorder it such that nums[0] < nums[1] > nums[2] < nums[3]...
    //Sort array, make extra array, fill input array from res
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> res(n);
        
    //i starts with 1 (odd index) and fills the greater numbers in increasing order in the odd indexes by making jumps of 2
    //j starts traversing from the larger to smaller number
    int i = 1, j = n - 1;
    while(j >= 0)
    {
        if(i >= n)  //When i completes filling larger number, it startes filling smaller number in even indexes starting from 0 & makes jumps of 2
            i = 0;
            
        res[i] = nums[j];
            
        i += 2;
        j--;
    }

    return res;
}

vector<int> wiggleSortEquality(vector<int> nums)    //TC = O(n)    SC = O(1)
{
    // Only work if reorder is such that nums[0] <= nums[1] => nums[2] <= nums[3]...
    //Through observation we can see that even indexes always contain smaller numbers & odd indexes always contian larger numbers
    //Traverse the list, if index i is even and element[i+1](odd) < element[i](even) then swap
    //Similarly, if index i is odd and element[i+1](even) > element[i](odd) then swap
    //The inequalities get handled themselves
    
    vector<int> res(nums.size());
    
    for(int i=0; i<nums.size(); i++)
        res[i] = nums[i];

    for(int i=0; i<nums.size(); i++)
    {
        if(i & 1 != 1)  //Even number
            if(nums[i] > nums[i+1])
                swap(nums[i], nums[i+1]);
        else //Odd number
            if(nums[i] < nums[i+1])
                swap(nums[i], nums[i+1]);
    }

    return res;
}