#include<bits/stdc++.h>

using namespace std;

//QUestion & Answer URL: https://youtu.be/gYmWHvRHu-s?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma

template<typename T>
void printVector(vector<T> v)
{
    cout<<"\n[";
    for(auto i:v)
        cout<<i<<",";
    cout<<"]";
}

bool allocationPossible(int barrier, int students, vector<int> pages)
{
    int allocatesStudent = 1, pagesAllocated = 0;
    for(int i=0; i<pages.size(); i++)
    {
        if(pages[i] > barrier)  //If number of pages is greater thaan barrier
            return false;

        if(pagesAllocated + pages[i] > barrier)
        {
            allocatesStudent += 1;
            pagesAllocated = pages[i];
        }
        else
            pagesAllocated += pages[i];
    }

    if(allocatesStudent > students)
        return false;
    return true;
}

int minimumAllocation(vector<int> pages, int students)
{
    if(pages.size() == 0)
        return 0;

    //Using Binary search
    //Search space is the from minimum no. of pages to sum of all pages
    int low = INT_MAX;
    int high = 0;
    for(int i=0; i<pages.size(); i++)
    {
        if(pages[i] < low)
            low = pages[i];
        high += pages[i];
    }

    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if(allocationPossible(mid, students, pages))
        {
            res = mid;  //Only store if allocation is possible
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
    
}

int main()
{
    int student = 2;
    int pg[] = {12, 34, 67, 90};
    vector<int> pages;
    for(int i=0; i<4; i++)
        pages.push_back(pg[i]);
        
    cout<<"Minimum of maximum of allocation is:"<<minimumAllocation(pages, student);
    return 0;
}