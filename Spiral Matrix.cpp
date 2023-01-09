#include<iostream>

using namespace std;

const int C = 3;

void SpiralPrint(int A[][C], int m, int n)      //O(m*n)
{
    int i, k = 0, l = 0;
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
   while(k < m && l < n)
   {
       //Print the first row from the remaining rows
       for(i=l; i<n; ++i)
           cout<<A[k][i]<<" ";

       k++;

       //Print the last column from the remainig columns
       for(i=k; i<m; ++i)
           cout<<A[i][n-1]<<" ";
       
       n--;

       //Print the last row from the remaining rows
       if(k < m)
       {
           for(i=n-1; i>=l; --i)
            cout<<A[m-1][i]<<" ";
        
            m--;

       }

       //Print the first column fro the remaining columns
       if (l < n)
       {
           for(i=m-1; i>=k; --i)
            cout<<A[i][l]<<" ";

            l++;
       }
       
   }

}

int main()
{
    int Arr[3][3] = {   {1, 2, 3},
                        {4, 5,  6},
                        {7, 8, 9}
                    };

    SpiralPrint(Arr, 3, 3);

    return 0;
}