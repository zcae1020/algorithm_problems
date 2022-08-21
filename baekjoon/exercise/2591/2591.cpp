#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

string s;
int ans;

void dfs(int idx)
{
    if (idx < 0)
    {
        ans++;
        return;
    }

    if (s[idx] != '0')
        dfs(idx - 1);
    if (idx > 0 && s[idx - 1] != '0')
    {
        int n = (s[idx - 1] - '0') * 10 + s[idx] - '0';
        if (n < 35)
            dfs(idx - 2);
    }
}

void Solution()
{
    cin >> s;

    dfs(s.size() - 1);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}