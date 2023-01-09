#include<iostream>

using namespace std;

//This an example of dynamic programming 
int LargestSumContiguousSubarray_1(int arr[], int n)        //O(n)
{   //Kadane's Algorithm: this does not work for negative number
    //because it will give 0 if the array has only negative numbers 
    int max_ending_here = 0;
    int max_so_far = 0;

    for(int i=0;i<n;i++)
    {
        max_ending_here = max_ending_here + arr[i];

        if(max_ending_here < 0)
            max_ending_here = 0;

        else if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}

int LargestSumContiguousSubarray_2(int arr[], int n)        //O(nnewmwemwwemqq)
{
    //Changing algorithm to work for negative number
    int curr_max = arr[0];
    int max_so_far = arr[0];

    for(int i=0;i<n;i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int A[6] = {-1, -2, 3, 4, -5, 7};
    int B[6] = {-1, -2, -3, -4, -5, -7};
    cout<<"The Largest Sum in the Contiguous Subaray is:"<<LargestSumContiguousSubarray_1(A,6);
    cout<<"\nThe Largest Sum in the Contiguous Subaray with only negative numbers is:"<<LargestSumContiguousSubarray_2(B,6);

    return 0;
}