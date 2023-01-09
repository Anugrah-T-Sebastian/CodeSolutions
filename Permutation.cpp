#include<bits/stdc++.h>

using namespace std;

void recurPermuted(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
        
    for(int i=0; i<nums.size(); i++)
    {
        if(!freq[i])    //If the element has not been added into the permutation
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermuted(ds, nums, ans, freq);
            freq[i] = 0;    //While the recursion is going back again mark it as unvisited;
            ds.pop_back();  //Remove the element from permutation
        }
    }
}
    
vector<vector<int>> permute1(vector<int>& nums) 
{
        //Method(1) - Using Recursion, DS & Map    TC=O(n!*n) SC=O(n)+O(n)
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];  //To used as ma to check if element has been added into the permutation
        for(int i=0; i<nums.size();i++)
            freq[i] = 0;
        recurPermuted(ds, nums, ans, freq);
        
        return ans;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void recurPermute(int index, vector<int>& nums, vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
vector<vector<int>> permute2(vector<int>& nums) 
{
    //Method(1) - Using Recursion, DS & Map    TC=O(n!*n) SC=O(n)+O(n)
    //Method(2) - Using Recursion, DS & Swapping TC=O(n!*n) SC=O(n)
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
        
    return ans;
        
}