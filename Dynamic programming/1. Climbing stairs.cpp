#include <bits/stdc++.h>

using namespace std;

// Maximum step size is given 2
// If #ways to reach step n = f(n) = f(n-1) + f(n-2)

int countNumberOfWaysToClimb(int n)
{
    int n0 = 1, n1 = 1;
    if (n == 0 || n == 1)
        return 1;

    int ways = 0;
    for (int i = 2; i <= n; i++)
    {
        ways = n1 + n0;
        n0 = n1;
        n1 = ways;
    }

    return ways;
}