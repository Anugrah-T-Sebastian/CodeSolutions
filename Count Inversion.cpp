#include<iostream>

using namespace std;

int InversionCount_1(int arr[], int n)      //O(n^2)
{
    int inv_count = 0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int InversionCount_2(int arr[], int n)      //O(nlogn)
{
    //This function sorts the input array and returns the number of inversions in the array
    //This is using an enhanced Merge Sort
    int temp[n];
    return _mergeSort(arr, temp, 0, n-1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if(right > left)
    {
        mid = (right + left)/2;

        //Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        //Merge the two parts
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;

    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i); //If confused, see examples
        }
    }

    //Copy the remaining elements to temp
    while(i <= mid -1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for(i=left; i<=right; i++)
        arr[i] = temp[i];

    return inv_count;

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int main()
{
    int Arr[5] = {2, 4, 1, 3, 5};

    cout<<"\nThe number of inversions using the 1st function:"<<InversionCount_1(Arr, 5);
    cout<<"\nThe number of inversions using the 2nd function:"<<InversionCount_2(Arr, 5);


    return 0;
}