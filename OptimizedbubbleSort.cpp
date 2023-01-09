#include<iostream>

using namespace std;

void optimizedBubbleSort(int arr[], int n)
{
    int i;
    //int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sorting...\n";
    //cout<<"Size:"<<n<<"\n";

    for (i = 0; i < n; i++)
    {
        bool flag = false;                          //Adding flag to check if the swapping really happens
        for(int j=0; j<n-j-1;j++)
        {
            cout<<"Ieration:"<<i+1<<"\n";
            if(arr[j] > arr[j+1])
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == false)
        {
            break;
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

    optimizedBubbleSort(A, num);
    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}