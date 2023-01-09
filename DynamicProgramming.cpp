#include<iostream>
#include<climits>

using namespace std;


//Fibonacci number using recurssion     Time complexity = O(2^n)
int fib_recursion(int n)        //Space complexity = O(n)
{
    if(n==0 || n==1)
        return n;

    else
        return fib_recursion(n-1) + fib_recursion(n-2);
}

//Fibonacci number using Top-Down DP(Recussion + Memoization)       Time complexity = O(n)
int fib_TopDownDP(int n, int *Fib)
{
    if(n==0 || n==1)
    {
        Fib[n] = n;
        return Fib[n];
    }

    //Already computed
    if(Fib[n] != -1)
        return Fib[n];

    else
    {
        //Compute & store
        Fib[n] = fib_TopDownDP(n-1,Fib) + fib_TopDownDP(n-2,Fib);
        return Fib[n];
    }
}

//Fibonacci number using Bottom-Up DP(Iterative + Memoization)      Time complexity = O(n)
int fib_BottomUpDP(int n)       //Space complexity = o(n)
{
    int *Fib = new int[n];
    Fib[0] = 0;     //Base case of recurssion becomes the assignment
    Fib[1] = 1;

    for(int i=2;i<=n;i++)
        Fib[i] = Fib[i-1] + Fib[i-2];

    return Fib[n];
}

int fib_ON(int n)       //Space complexity = O(1)
{
    int fib1 = 0, fib2 = 1;
    int fib3;
    for(int i=2;i<=n;i++)
    {
        //Add previous 2 Fibonacci numbers to compute next Fibonacci number & update the previous Fib. numbers
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
    return fib3;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Ladders problem using recursion       O(k^n)
int ways_Recursion(int N)       
{
    //For Ground level
    if(N==0)
        return 1;

    if(N<0)     //For Below Groud level there is no way to get to the above
        return 0;
    
    int ans = ways_Recursion(N-1) + ways_Recursion(N-2) + ways_Recursion(N-3);
    return ans;

}

int ways_Recursion(int N, int k)
{
    if(N==0)
        return 1;

    if(N<0)
        return 0;

    int ans = 0;
    for(int j=1;j<=k;j++)
    {
        ans += ways_Recursion(N-j,k);
    }
    return ans;
}

//Ladders problem using Top-Down DP
// int way_TopDownDP(int N, int *Ways)
// {
//     if()
// }

//Ladders problem using Bottom-Up DP
int ways_BottomUpDP(int N, int k)      //Time complexity = O(N*k)
{
    int *Ways = new int[N];
    Ways[0] = 1;
    for(int steps=1;steps<=N;steps++)
    {
        Ways[steps] = 0;
        for(int j=1;j<=k;j++)
        {
            if(steps-j >= 0)
                Ways[steps] += Ways[steps-j];
        }
    }

    cout<<endl;
    for(int i=0;i<=N;i++)
        cout<<Ways[i]<<" ";

    return Ways[N];
}

int ways_BottomUpDPImproved(int N, int k)      //Time complexity = O(N)
{
    int *Ways = new int[N]{0};
    Ways[0] = Ways[1] = 1;
    for(int step=2;step<=N;step++)
    {
        if(step-k-1 < 0)
            Ways[step-k-1] = 0; 

        Ways[step] = Ways[step-1] + Ways[step-1] - Ways[step-1-k]; 
    }
    
    cout<<endl;
    for(int i=0;i<=N;i++)
        cout<<Ways[i]<<" ";

    return Ways[N];
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Minimum coins using recursion
int minCoins_Recursion(int coins[], int amount, int N)
{
    //Base case
    if(amount==0)
        return 0;

    //Rec Case
    int coinsNeeded = INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(amount-coins[i] >= 0)
        {
            int smallerAns = minCoins_Recursion(coins,amount-coins[i],N);
            if(smallerAns!=INT_MAX)
            {
                coinsNeeded = min(coinsNeeded,smallerAns+1);
            }
        }
    }
    return coinsNeeded;
}

//Minimum coins using recursion
int minCoins_BottomUpDP(int coins[], int amount, int N)
{
    int *MinCoins = new int[amount+1];
    

    for(int i=0;i<=amount;i++)
        MinCoins[i] = INT_MAX;

    MinCoins[0] = 0;
    for(int rupay=1;rupay<=amount;rupay++)
    {
        //Iterate over coins
        for(int i=0;i<N;i++)
        {
            if(coins[i] <= rupay)
            {
                int smallerAns = MinCoins[rupay-coins[i]];
                if(smallerAns!=INT_MAX)
                {
                    MinCoins[rupay] = min(MinCoins[rupay],smallerAns+1);
                }
            }
        }
    }
    return MinCoins[amount];
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//0/1-Knapsack problem using recursion
int knapsack_01(int wts[], int prices[], int N, int W)
{
    if(N==0 || W==0)        //If there are no items or with the capacity of Knapsack is zero
        return 0;

    int include = 0, exclude = 0;
    
    //Including current item
    if(wts[N-1] <= W)
        include = prices[N-1] + knapsack_01(wts,prices,N-1,W-wts[N-1]);

    //Excluding current item
    exclude = 0 + knapsack_01(wts,prices,N-1,W);

    return max(include,exclude);
    
}

//0/1-Knapsack unbounded problem using recursion
int knapsack_01Unbounded(int wts[], int prices[], int N, int W)
{
    /*In an unbounded knapsack, an item can be picked up multiple times*/
    
    if(N==0 || W==0)        //If there are no items or with the capacity of Knapsack is zero
        return 0;

    int include = 0, exclude = 0;
    
    //Including current item
    if(wts[N-1] <= W)
        include = prices[N-1] + knapsack_01Unbounded(wts,prices,N,W-wts[N-1]);      //Do not reduce the number of item

    //Excluding current item
    exclude = 0 + knapsack_01Unbounded(wts,prices,N-1,W);       //Do not reduce the number of items

    return max(include,exclude);
    
}

//0/1-Knapsack problem using Bottom-Up DP
int knapsack_01BottomUpDP(int wts[], int prices[], int N, int W)
{
    int Dp[N+1][W+1];

    for(int obj=0;obj<=N;obj++)
    {
        for(int w=0;w<=W;w++)
        {
            if(obj==0 || w==0)
                Dp[obj][w] = 0;

            else if(wts[obj-1]>w)
                Dp[obj][w] = Dp[obj-1][w];

            else
                Dp[obj][w] = max(prices[obj-1] + Dp[obj-1][w-wts[obj-1]],Dp[obj-1][w]);
        }
    }
    return Dp[N][W];
}

//0/1-Knapsack unbounded problem using Bottom-Up DP
int knapsack_01BottomUpDPUnbounded(int wts[], int prices[], int N, int W)
{
    int Dp[N+1][W+1];

    for(int obj=0;obj<=N;obj++)
    {
        for(int w=0;w<=W;w++)
        {
            if(obj==0 || w==0)
                Dp[obj][w] = 0;

            else if(wts[obj-1]>w)
                Dp[obj][w] = Dp[obj-1][w];

            else
                Dp[obj][w] = max(prices[obj-1] + Dp[obj][w-wts[obj-1]],Dp[obj-1][w]);
        }
    }
    return Dp[N][W];
}

/*------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    //Fibonacci numbers
    // cout<<"\n----------------------------------------------------------------------------------------------------------"
    //     <<"\nFibonacci numbers";
    //     cout<<"\nFibonacci using recurssion:"<<fib_recursion(10);
    //     int Fib[100];
    //     for(int i=0;i<100;i++)
    //         Fib[i] = -1;
    //     cout<<"\nFibonacci using Top-Down DP:"<<fib_TopDownDP(30,Fib);
    //     cout<<"\nFibonacci using Bottom-Up DP:"<<fib_BottomUpDP(30);
    //     cout<<"\nFibonacci using Bottom-Up DP:"<<fib_ON(30);


    //Ladders probelem
    // cout<<"\n----------------------------------------------------------------------------------------------------------"
    //     <<"\nLadders probelem";
    //     /*We have a ladder with N steps in it. A person can take either 1, 2 or 3 steps
    //       at a time OR k i.e. maximum possible jumb that we can take. Find the total 
    //       number of ways that he can reach the top*/
    //     //cout<<"\nNumber of ways when N=4 & k=3 is:"<<ways_Recursion(4);
    //     //cout<<"\nNumber of ways when N=4 & k=3 is:"<<ways_Recursion(4,3);
    //     cout<<"\nNumber of ways when N=4 & k=3 is:"<<ways_BottomUpDP(5,4);
    //     cout<<"\nNumber of ways when N=4 & k=3 is:"<<ways_BottomUpDPImproved(5,4);


    //Minimum coins needed
    // cout<<"\n--------------------------------------------------------------------------------------------------------------------"
    //     <<"\nMinimum coins needed Problem";
    //     /*We have coins of different denominations. Find out the minimum number of coins
    //       needed to make a given sum of money*/
    //     int us_coins[] = {1, 7, 10};
    //     // int N1 = 3;
    //     // int amount1 = 15;
    //     // cout<<"\nMinimum coins:"<<minCoins_Recursion(us_coins,amount1,N1);
    //     // cout<<"\nMinimum coins:"<<minCoins_BottomUpDP(us_coins,amount1,N1);
    //     int indian_coins[] = {1, 2, 5, 10, 50};
    //     int N2 = 5; 
    //     int amount2 = 39;
    //     //cout<<"\nMinimum coins:"<<minCoins_Recursion(indian_coins,amount2,N2);
    //     cout<<"\nMinimum coins using Bottom-Up DP:"<<minCoins_BottomUpDP(indian_coins,amount2,N2);

    
    //0/1-Knapsack
    cout<<"\n----------------------------------------------------------------------------------------------------------------------"
        <<"\n0/1Knapsack Problem";
        int wts[] = {2,7,3,4};
        int prices[] = {5,20,20,10};
        int n = 4;
        int W = 11;
        cout<<"\nMaximum Profit using recursion:"<<knapsack_01(wts,prices,n,W);
        cout<<"\nMaximum Profit using Bottom-Up DP:"<<knapsack_01BottomUpDP(wts,prices,n,W);




    return 0;

} 