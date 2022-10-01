vector<int> manacher(auto &s)
{
    vector<int> p(s.size());
    int n = s.size(), r = -1, k = -1;
    for (int i = 0; i < n; i++)
    {
        if (i <= r)
            p[i] = min(r - i, p[2 * k - i]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
            p[i]++;
        if (r > i + p[i])
            r = i + p[i], k = i;
    }
    return p;
}