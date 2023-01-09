#include<bits/stdc++.h>

using namespace std;

//QUestion & Answer URL: https://youtu.be/wSOfYesTBRk?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma

template<typename T>
void printVector(vector<T> v)
{
    cout<<"\n[";
    for(auto i:v)
        cout<<i<<",";
    cout<<"]";
}

bool canPlaceCows(vector<int> distance, int n, int cows, int dist)
{
    //Place cows using using Greedy Method
    int co_ordinate = distance[0]; //Place the 1st cow at 1st position
    int count = 0;
    for(int i=1; i<n; i++)
    {
        if(distance[i] - co_ordinate >= dist)  
        {
            count++;
            co_ordinate = distance[i];
        }

        if(count == cows)
            return true;
    }

    return false;
}

//Find the Largest of the minimal distances between each cow
//The largest minimal distance is monotonically increasing, so we can use Binary Search. low = (minimum ditance) high=(maximum-minimum)
void placeCows(vector<int> distance, int cows)
{
    int res, n = distance.size();
    int low = 1;
    int high = distance[n-1] - distance[0];
    while (low <= high)
    {
        int mid = (low+high)>>1;

        if(canPlaceCows(distance, n, cows,mid))
        {
            res = mid;
            low = mid+1; //Move the search place to right & try to find larger result
        }
        else
        {
            high = mid-1;
        }

    }
    
}