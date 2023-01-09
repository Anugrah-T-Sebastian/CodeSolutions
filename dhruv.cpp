int solve(int n, string s, int c[])
{
    vector<int> vec;
    int cost = 0;
    for (int i = 0; i < n / 2; i += 2)
    {
        if ((s[i] == s[n - 1 - i] && s[i + 1] == s[n - 2 - i]) || (s[i] == s[n - 2 - i] && s[i + 1] == s[n - 1 - i]))
        {
            continue;
        }
        vec.clear();
        vec.push_back(c[i]);
        vec.push_back(c[i + 1]);
        vec.push_back(c[n - 1 - i]);
        vec.push_back(c[n - 2 - i]);
        sort(vec.begin(), vec.end());
        int cur = vec[0] + vec[1];
        if (s[i] == s[n - 1 - i])
            cur = min({cur, c[i + 1], c[n - 2 - i]});
        if (s[i] == s[n - 2 - i])
            cur = min({cur, c[i + 1], c[n - 1 - i]});
        if (s[i + 1] == s[n - 1 - i])
            cur = min({cur, c[i], c[n - 2 - i]});
        if (s[i + 1] == s[n - 2 - i])
            cur = min({cur, c[i], c[n - 1 - i]});
        cost += cur;
    }
    return cost;
}