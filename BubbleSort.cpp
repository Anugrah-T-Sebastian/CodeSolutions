#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i;
    //int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sorting...\n";
    //cout<<"Size:"<<n<<"\n";

    for (i = 0; i < n; i++)
    {
        for(int j=0; j<n-j-1;j++)
        {
            cout<<"Ieration:"<<i+1<<"\n";
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}

int main()
{
    int num, A[20];
    cout<<"Enter the size of the array\n";
    cin>>num;
    cout<<"Enter the elementso of the array\n";
    for(int i=0; i<num; i++)
    {
        cin>>A[i];
    }

    bubbleSort(A, num);
    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}