#include<iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for(i=1; i<n; i++)
    {
        cout<<"iteration:"<<i+1<<"\n";
        key = arr[i];
        j = i-1;
         while(j>=0 && arr[j]>key)
         {
            //Start if the value of the element preceeding the key is greater than it
             arr[j+1] = arr[j];         //Increase the position of the element by one
             j = j -1;                  //Reduce the value of j to check whether values of the element before preceeding element in the further iterartions
         }

         //Now the correct index of the element is stored in the j after the execution of the loop
         arr[j+1] = key;                //Assign the value of the element in the correct position

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

    insertionSort(A, num);
    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}