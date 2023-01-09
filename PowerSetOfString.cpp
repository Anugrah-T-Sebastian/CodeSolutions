#include<bits/stdc++.h>

using namespace std;

template<typename T>
void printVector(vector<T> v)
{
    cout<<"\n[";
    for(auto i:v)
        cout<<i<<",";
    cout<<"]";
}

//Pick the elements using bits
vector<string> createPowerSet(string s)
{
    vector<string> powerSet;
    int n = s.size();
    int N = 1<<n;    //=2^
    for(int num=0; num<N; num++)
    {
        string subString = "";
        for(int i=0; i<n; i++)
        {
            if(num & (1<<i))
                subString += s[i];
        }
        powerSet.push_back(subString);
    }

    return powerSet;
}

int main()
{
    string s;
    cout<<"\nEnter a string:";
    cin>>s;

    vector<string> power = createPowerSet(s);
    printVector(power);

    return 0;
}