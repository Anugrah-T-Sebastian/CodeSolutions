#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> v)
{
    cout << "\n[";
    for (auto i : v)
        cout << i << ", ";
    cout << "]";
}

void printGrid(vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void pattern(int flowers)
{
    int n = 2 * flowers;
    vector<vector<char>> grid(n, vector<char>(n, 'A' + flowers - 1));
    for (int i = 1; i < flowers; i++)
    {
        for (int j = 1; j < flowers; j++)
        {
            if (grid[i - 1][j] == grid[i][j - 1])
            {
                grid[i][j] = grid[i - 1][j - 1] - 1;
                // Copy the value to corresponding indexes as well
                grid[i][n - j - 1] = grid[i][j];
                grid[n - i - 1][j] = grid[i][j];
                grid[n - i - 1][n - j - 1] = grid[i][j];
            }
            else
            {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]);
                // Copy the value to corresponding indexes as well
                grid[i][n - j - 1] = grid[i][j];
                grid[n - i - 1][j] = grid[i][j];
                grid[n - i - 1][n - j - 1] = grid[i][j];
            }
        }
    }

    printGrid(grid);
}

//=========================================================================================================================================
// Q2. aggregate temperature

long getMaxAggergateTemperatureChange(vector<int> tempChange)
{
    int n = tempChange.size();
    long maxAggregateTemp = INT16_MIN;
    vector<long> temp(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            temp[0] = tempChange[0];
            continue;
        }
        temp[i] = temp[i - 1] + tempChange[i]; // Not explicitly typecasting because temp element is already long. long + int = long
    }

    for (int i = 0; i < n; i++)
    {
        temp[i] = max(temp[i], temp[n] - temp[i] + tempChange[i]);
        maxAggregateTemp = max(temp[i], maxAggregateTemp);
    }

    return maxAggregateTemp;
}

//===============================================================================================================================================
// Q3. Virtual private server

long minMemory(vector<int> process, int m)
{
    int n = process.size();
    int window = 0, totalMemory = 0;
    for (int i = 0; i < m; i++)
        window += process[i];

    for (auto i : process)
        totalMemory += i;

    int maxMemoryBlock = window;
    for (int i = 1; i < (n - m + 1); i++)
    {
        window += -process[i - 1] + process[i + m - 1];
        if (window > maxMemoryBlock)
            maxMemoryBlock = window;
    }

    return (totalMemory - maxMemoryBlock);
}

//=================================================================================================================================================
// Q4. Encrypted Number

vector<int> getEncryptedNumber(vector<int> numbers)
{
    int n = numbers.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0)
                dp[i][j] = numbers[j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % 10;
        }
    }

    vector<int> answer;
    for (int i = 0; i < 2; i++)
        answer.push_back(dp[n - 2][i]);

    return answer;
}

int main()
{
    // pattern(3);
    vector<int> q2 = {-1, 2, 3};
    cout << "\n"
         << getMaxAggergateTemperatureChange(q2);
    // vector<int> q3 = {4, 6, 10, 8, 2, 1};
    // cout << "\n"
    //      << minMemory(q3, 3);

    // vector<int> a4, q4 = {4, 5, 6, 7};
    // a4 = getEncryptedNumber(q4);
    // cout << "\n";
    // printVector(a4);

    return 0;
}