#include<bits/stdc++.h>

using namespace std;

//Print vector function
void printVector(vector<int> v)
{
    cout<<"\n[";
    for(int i : v)
        cout<<i<<", ";
    cout<<"]";
}

void printPairVector(vector<pair<int, int>> v)
{
    cout<<"\n[";
    for(auto i : v)
        cout<<"{"<<i.first<<", "<<i.second<<"}, ";
    cout<<"]";
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

//Define a  reverse comparator function
bool compare(int a, int b)
{
    return a < b;
}

//Define a  reverse comparator function
bool reverseCompare(int a, int b)
{
    return a > b;
}

//Define a  reverse comparator function
bool pairCompareDescending(pair<int, int> a, pair<int, int> b)
{
    return a > b;
}

int main()
{
    vector<int> v1 = {4, 1, 7, 8, 3, 2};
    //Sort function works from 1st to last element, but the last one is not included. So always give range:[a, a+n) instead of [a, a+n-1)
    sort(v1.begin(), v1.end());
    printVector(v1);

    vector<int> v2 = {4, 1, 7, 8, 3, 2};
    sort(v2.begin(), v2.end(), reverseCompare);
    printVector(v2);

    vector<pair<int, int>> vp = {{1,2}, {3,4}, {5,6},{5,5}};
    sort(vp.begin(), vp.end(), pairCompareDescending);
    printPairVector(vp);

    return 0;
}