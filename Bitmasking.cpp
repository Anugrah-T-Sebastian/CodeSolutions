#include<iostream>

using namespace std;

int countSetBits(int n)        //O(No. of bit)
{
    //Function counts number of set bit
    int count = 0;
    while (n>0)
    {
        count += (n&1);
        n = n>>1;
    }
    return count;
}

int countSetBitsImproved(int n)     //O(No. of set bits)
{
    int count = 0;
    while(n!=0)
    {
        //Each iteration removes one set bit
        count++;
        n = n & (n-1);
    }
    return count;
}

int  main()
{
    int n;
    cout<<"\nEnter a number:";
    cin>>n;
    cout<<"\nNumber of set bits in "<<n<<" is:"<<countSetBits(n);
    cout<<"\nNumber of set bits in "<<n<<" is:"<<countSetBitsImproved(n);

    return 0;
}