#include <bits/stdc++.h>

using namespace std;

void getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (pow(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    cout << "Nth root lies in range:[" << low << "," << high << "]";
}

int main()
{
    int n, m;
    cin >> n >> m;
    getNthRoot(n, m);
    return 0;
}