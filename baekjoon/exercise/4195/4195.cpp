#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int f;
unordered_map<string, string> ss;
unordered_map<string, int> si;

string find(string u)
{
    if (u == ss[u])
        return u;

    return ss[u] = find(ss[u]);
}

int merge(string u, string v)
{
    u = find(u), v = find(v);

    if (u == v)
        return si[u];

    ss[u] = v, si[u] = si[u] + si[v];

    return si[v] = si[u];
}

void Solution()
{
    cin >> f;

    while (f--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (si[s1] == 0)
            ss[s1] = s1, si[s1] = 1;
        if (si[s2] == 0)
            ss[s2] = s2, si[s2] = 1;

        cout << merge(s1, s2) << '\n';
    }

    ss.clear(), si.clear();
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}