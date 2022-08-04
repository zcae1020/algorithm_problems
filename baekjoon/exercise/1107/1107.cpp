#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, M, a[10], ans;
string s;

void dfs(int idx, int num)
{
    if (idx == s.size())
    {
        if (num == 0 && a[0])
            return;
        ans = min(ans, (int)to_string(num).size() + abs(N - num));
        return;
    }

    int multi = 1;
    for (int i = 1; i < s.size() - idx; i++, multi *= 10);

    idx++;
    if (!num)
        dfs(idx, num);
    for (int i = 0; i < 10; i++)
        if (!a[i])
            dfs(idx, num + multi * i);
}

void Solution()
{
    cin >> s >> M;
    N = stoi(s);
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    ans = abs(100 - N);

    dfs(-1, 0);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}