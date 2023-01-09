#include<bits/stdc++.h>

using namespace std;


void printVector(vector<int> v)
{
    cout<<"\n[";
    for(auto i:v)
        cout<<i<<",";
    cout<<"]";
}

void func(int index, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if(index == N)
    {
        sumSubset.push_back(sum);
        return;
    }

    //Pick the element
    func(index+1, sum+arr[index], arr, N, sumSubset);

    //Do not pick the element
    func(index+1, sum, arr, N, sumSubset);
}

vector<int> subsetSum(vector<int> arr, int N)
{
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());

    return sumSubset;
}

int main()
{
    system("cls");
    int N, input;
    vector<int> Set;
    cout<<"\nEnter the number of elements in the Set:";
    cin>>N;

    cout<<"Enter the element of the Subset:";
    for(int i=0; i<N; i++)
    {
        cin>>input;
        Set.push_back(input);
    }

    printVector(Set);
    vector<int> v = subsetSum(Set, N);
    printVector(v);
    return 0;
}